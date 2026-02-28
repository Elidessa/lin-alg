#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void main(){
				matrix* foo = create_matrix(1000,1000);
				for(int i = 0; i < foo->x*foo->y; i++)foo->elements[i] = i; 
			
				matrix* bar = create_matrix(1000,1000);
				for(int i = 0; i < bar->x*bar->y; i++)bar->elements[i] = i; 

				void* ptr = matrix_multiply(foo,bar);
				if(ptr != 0)printf("gick");

				free(ptr);

}

void print_matrix(matrix* mtrx){
				for(int i = 0; i < mtrx->y*mtrx->x; i++){
								printf("%d ",mtrx->elements[i]);
								if(i % mtrx->x == mtrx->x - 1){ printf("\n");}
				}
}
matrix* matrix_multiply(matrix *mtrx1, matrix *mtrx2){
			if(mtrx1->x != mtrx2->y) return 0;	

      matrix *retptr = create_matrix(mtrx2->x,mtrx1->y); 

			int x = mtrx2->x;
			int y = mtrx1->y;

			for (int i = 1; i <= x*y; i++){
								static int xcounter = 0;
								static int ycounter = 0;
								int sum = 0;

								for(int j = xcounter; j < xcounter+mtrx1->x; j++){
												sum += mtrx1->elements[j]*mtrx2->elements[ycounter + (i-1)%y];
												ycounter+=y;
								}
								retptr->elements[i-1] = sum;

								if(i%x == 0) xcounter +=mtrx1->x;
								ycounter = 0;
				}
				return retptr;
}

int xy_to_index(matrix *mtrx, int x, int y){
				if(y%2 == 0){
								return(y*mtrx->x) + (mtrx->x-1) - x;
				}
				return y*mtrx->x + x;
}
void matrix_factor_multiply(matrix *mtrx, int factor){
				for(int i = 0; i < mtrx->x*mtrx->y; i++){
								mtrx->elements[i] *= factor;
				}
}
matrix* create_matrix(int x, int y){
				if(x == 0 || y == 0) return 0;

				matrix* retptr = (matrix*)malloc(sizeof(matrix)+x*y*sizeof(int));
				retptr->x = x;
				retptr->y = y;

				return retptr;
}
