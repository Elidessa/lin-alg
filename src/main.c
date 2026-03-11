#include "matrix.h"

int main(int argc, char** argv){
		int bar[] = {2,0,3,
								 1,2,1,
								 3,0,2};
		matrix* foo = matrix_create(3, 3);
		matrix_fill(foo, bar);	
		matrix_print(foo);

		return 0;
}


int matrix_determinant(matrix* mtrx){
		if(mtrx->x != mtrx->y)return 0;

		//För 2x2
		if(mtrx->x)return mtrx->elements[0]*mtrx->elements[3] - mtrx->elements[1]*mtrx->elements[2];
		return 0;
}

