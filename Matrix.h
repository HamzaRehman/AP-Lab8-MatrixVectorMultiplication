#define MATRIX_NOT_CREATED 0
#define MATRIX_CREATED 1
#define MATRIX_ROW_WISE 2
#define MATRIX_COLUMN_WISE 3

// Matrix structure
typedef struct MatrixStruct {
	short created;
	short situateID;
	int rows;
	int columns;
	int size;
	unsigned int *matrix;
} Matrix;

// Related Functions
Matrix createMatrix(short situateID, int rows, int columns);
int getCellIndex(Matrix *mat, int i, int j);
void setMatrixCell(Matrix *mat, int i, int j, int value);
int getMatrixCell(Matrix *mat, int i, int j);
void populateMatrix(Matrix *mat, int limit);
void printMatrix(Matrix *mat);
int getNumOfRows(Matrix *mat);
int getNumOfColumns(Matrix *mat);
int getOrderOfMatrix(Matrix *mat);
