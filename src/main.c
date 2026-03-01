#include <stdio.h>
#include <stdlib.h>
#include "main.h"


void main(){
				/*
				matrix* foo = create_matrix(1000,1000);
				for(int i = 0; i < foo->x*foo->y; i++)foo->elements[i] = i; 
			
				matrix* bar = create_matrix(1000,1000);
				for(int i = 0; i < bar->x*bar->y; i++)bar->elements[i] = i; 

				void* ptr = matrix_multiply(foo,bar);
				if(ptr != NULL)printf("gick");

				free(ptr);
				*/
				print_matrix(create_identity_matrix(4));

}

void print_matrix(matrix* mtrx){
				for(int i = 0; i < mtrx->y*mtrx->x; i++){
								printf("%d ",mtrx->elements[i]);
								if(i % mtrx->x == mtrx->x - 1){ printf("\n");}
				}
}
matrix* matrix_multiply(matrix *mtrx1, matrix *mtrx2){
			if(mtrx1->x != mtrx2->y) return NULL;	

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
matrix* create_identity_matrix(int size){
				if(size == 0)return NULL;

				matrix* retptr = create_matrix(size,size);

				for(int i = 0; i < size*size; i++){
								retptr->elements[i] = 0;
								if(i%(size+1) == 0)retptr->elements[i] = 1;
				}


				return retptr;
}
