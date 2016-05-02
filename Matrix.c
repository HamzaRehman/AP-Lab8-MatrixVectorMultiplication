#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matrix.h"

Matrix createMatrix(short situateID, int rows, int columns) {
	Matrix mat = {MATRIX_CREATED, situateID, rows, columns, (rows * columns), (unsigned int *) malloc(sizeof(int) * (rows * columns))};
	return mat;
}
int getCellIndex(Matrix *mat, int i, int j) {
	switch(mat->created) {
	case MATRIX_CREATED:
		if(mat->situateID == MATRIX_ROW_WISE) {
			return i + (j * mat->rows);
		}
		else if(mat->situateID == MATRIX_COLUMN_WISE) {
			return (i * mat->columns) + j;
		}
		break;
	default:
		printf("Error! Matrix not created yet. Create your matrix first.\n");
	}
	return 0;
}
void setMatrixCell(Matrix *mat, int i, int j, int value) {
	switch(mat->created) {
	case MATRIX_CREATED:
		mat->matrix[getCellIndex(mat, i, j)] = value;
		break;
	default:
		printf("Error! Matrix not created yet. Create your matrix first.\n");
	}
}
int getMatrixCell(Matrix *mat, int i, int j) {
	switch(mat->created) {
	case MATRIX_CREATED:
		return mat->matrix[getCellIndex(mat, i, j)];
		break;
	default:
		printf("Error! Matrix not created yet. Create your matrix first.\n");
	}
	return 0;
}
void populateMatrix(Matrix *mat, int limit) {
	switch(mat->created) {
	case MATRIX_CREATED:
		srand((unsigned int) mat->size * time(NULL));
		int i, j;
		for (i = 0; i < mat->rows; i++) {
			for (j = 0; j < mat->columns; j++) {
				mat->matrix[getCellIndex(mat, i, j)] = rand() % limit;
			}
		}
		break;
	default:
		printf("Error! Matrix not created yet. Create your matrix first.\n");
	}
}
void printMatrix(Matrix *mat) {
	switch(mat->created) {
	case MATRIX_CREATED:
		printf("Matrix : ");
		int i, j;
		for (i = 0; i < mat->rows; i++) {
			for (j = 0; j < mat->columns; j++) {
				printf("%d\t", mat->matrix[getCellIndex(mat, i, j)]);
			}
			printf("\n\t ");
		}
		printf("\n");
		break;
	default:
		printf("Error! Matrix not created yet. Create your matrix first.\n");
	}
}
int getNumOfRows(Matrix *mat) {
	switch(mat->created) {
	case MATRIX_CREATED:
		return mat->rows;
		break;
	default:
		printf("Error! Matrix not created yet. Create your matrix first.\n");
	}
	return 0;
}
int getNumOfColumns(Matrix *mat) {
	switch(mat->created) {
	case MATRIX_CREATED:
		return mat->columns;
		break;
	default:
		printf("Error! Matrix not created yet. Create your matrix first.\n");
	}
	return 0;
}
int getOrderOfMatrix(Matrix *mat) {
	switch(mat->created) {
	case MATRIX_CREATED:
		return mat->size;
		break;
	default:
		printf("Error! Matrix not created yet. Create your matrix first.\n");
	}
	return 0;
}
