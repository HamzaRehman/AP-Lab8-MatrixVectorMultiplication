#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Vector.h"
#include "Matrix.h"

#define NUM 5
#define NUM_OF_THREADS 4

int startFrom = 0;

typedef struct MVData {
	Vector vector;
	Matrix matrix;
	Matrix resultantMatrix;
} MxV_Data;

void *rowOfMatrixIntoColumnOfVector(void *data) {
	int i, j;
	for(i = startFrom++; i < ((MxV_Data *) data)->matrix.rows; i += NUM_OF_THREADS) {
		for(j = 0; j < ((MxV_Data *) data)->vector.size; j++) {
			setMatrixCell(	&(((MxV_Data *) data)->resultantMatrix), i, 0,
							getMatrixCell(&(((MxV_Data *) data)->resultantMatrix), i, 0) +
							getMatrixCell(&(((MxV_Data *) data)->matrix), i, j) *
							getVectorAxisValue(&(((MxV_Data *) data)->vector), j));
		}
	}
}

Matrix matrixCrossVector(Matrix matrix, Vector vector) {
	Matrix resultantMatrix = createMatrix(MATRIX_COLUMN_WISE, matrix.rows, 1);
	if(matrix.columns == vector.size) {
		MxV_Data mvdata = {vector, matrix, resultantMatrix};
		int i, returnCode;
		pthread_t threads[NUM_OF_THREADS];
		for(i = 0; i < NUM_OF_THREADS; i++) {
			returnCode = pthread_create(&threads[i], NULL, rowOfMatrixIntoColumnOfVector, (void *) &mvdata);
			if (returnCode) {
				printf("ERROR; return code from pthread_create() is %d.\n", returnCode);
				exit(-1);
			}
		}
		for(i = 0; i < NUM_OF_THREADS; i++) {
			pthread_join(threads[i], NULL);
		}
	} else {
		printf("\tSorry but the matrix and vector are not compatible for multiplication.\n");
	}
	return resultantMatrix;
}

int main() {
	Vector vector = createVector(NUM);
	Matrix matrix = createMatrix(MATRIX_COLUMN_WISE, NUM, NUM);
	populateVector(&vector, 10);
	populateMatrix(&matrix, 10);

	Matrix resultantMatrix = matrixCrossVector(matrix, vector);

	printVector(&vector);
	printMatrix(&matrix);
	printMatrix(&resultantMatrix);

	return 0;
}
