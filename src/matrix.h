
typedef struct {
				int x;
				int y;
				int elements[];
}matrix;


void matrix_print(matrix *mtrx);
matrix* matrix_multiply(matrix *mtrx1, matrix *mtrx2);
int xy_to_index(matrix *mtrx, int x, int y);
void matrix_factor_multiply(matrix *mtrx, int factor);
matrix* matrix_create(int x, int y);
matrix* matrix_create_identity(int size);
matrix* matrix_transpose(matrix* mtrx);
matrix* matrix_append_right(matrix* mtrx1, matrix* mtrx2);
void matrix_print_2(matrix* mtrx1, matrix* mtrx2);
void matrix_fill(matrix* mtrx, int* values);
int matrix_determinant(matrix* mtrx);

