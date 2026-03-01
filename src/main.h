
typedef struct {
				int x;
				int y;
				int elements[];
}matrix;


void print_matrix(matrix *mtrx);
matrix* matrix_multiply(matrix *mtrx1, matrix *mtrx2);
int xy_to_index(matrix *mtrx, int x, int y);
void matrix_factor_multiply(matrix *mtrx, int factor);
matrix* create_matrix(int x, int y);
matrix* create_identity_matrix(int size);
