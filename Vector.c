#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Vector.h"

Vector createVector(int size) {
	Vector vec = {VECTOR_CREATED, size, (unsigned int *) malloc(sizeof(int) * size)};
	return vec;
}
void setVectorAxisValue(Vector *vec, int axis, int value) {
	switch(vec->created) {
	case VECTOR_CREATED:
		vec->vector[axis] = value;
		break;
	default:
		printf("Error! Vector not created yet. Create your vector first.\n");
	}
}
int getVectorAxisValue(Vector *vec, int axis) {
	switch(vec->created) {
	case VECTOR_CREATED:
		return vec->vector[axis];
		break;
	default:
		printf("Error! Vector not created yet. Create your vector first.\n");
	}
	return 0;
}
void populateVector(Vector *vec, int limit) {
	switch(vec->created) {
	case VECTOR_CREATED:
		srand((unsigned int) vec->size * time(NULL));
		int i;
		for(i = 0; i < vec->size; i++) {
			vec->vector[i] = rand() % limit;
		}
		break;
	default:
		printf("Error! Vector not created yet. Create your vector first.\n");
	}
}
void printVector(Vector *vec) {
	switch(vec->created) {
	case VECTOR_CREATED:
		printf("Vector: (");
		int i;
		for(i = 0; i < vec->size-1; i++) {
			printf("%d, ", vec->vector[i]);
		}
		printf("%d)\n\n", vec->vector[vec->size-1]);
		break;
	default:
		printf("Error! Vector not created yet. Create your vector first.\n");
	}
}
int getTotalNumberOfVectorDimensions(Vector *vec) {
	switch(vec->created) {
	case VECTOR_CREATED:
		return vec->size;
		break;
	default:
		printf("Error! Vector not created yet. Create your vector first.\n");
	}
	return 0;
}
