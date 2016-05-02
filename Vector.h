#define VECTOR_NOT_CREATED 0
#define VECTOR_CREATED 1

// Vector structure
typedef struct VectorStruct {
	short created;
	int size;
	unsigned int *vector;
} Vector;

// Related Functions
Vector createVector(int size);
void setVectorAxisValue(Vector *vec, int axis, int value);
int getVectorAxisValue(Vector *vec, int axis);
void populateVector(Vector *vec, int limit);
void printVector(Vector *vec);
int getTotalNumberOfVectorDimensions(Vector *vec);
