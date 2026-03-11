#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
void matrix_fill(matrix* mtrx, int* values){
		for(int i = 0; i < mtrx->y*mtrx->x; i++){
				mtrx->elements[i] = *values;
				values++;
		}
}
void matrix_print(matrix* mtrx){
		for(int i = 0; i < mtrx->x; i++)printf("__");
		printf("\n");

		for(int i = 0; i < mtrx->y*mtrx->x; i++){
				printf("%d ",mtrx->elements[i]);
				if(i % mtrx->x == mtrx->x - 1){ printf("\n");}
		}
		for(int i = 0; i < mtrx->x; i++)printf("__");
		printf("\n");
}
matrix* matrix_multiply(matrix *mtrx1, matrix *mtrx2){
		if(mtrx1->x != mtrx2->y) return NULL;	

		matrix *retptr = matrix_create(mtrx2->x,mtrx1->y); 

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

int xy_to_iddex(matrix *mtrx, int x, int y){
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
matrix* matrix_create(int x, int y){
		if(x == 0 || y == 0) return 0;

		matrix* retptr = (matrix*)malloc(sizeof(matrix)+x*y*sizeof(int));
		retptr->x = x;
		retptr->y = y;


		return retptr;
}
matrix* create_identity_matrix(int size){
		if(size == 0)return NULL;

		matrix* retptr = matrix_create(size,size);

		for(int i = 0; i < size*size; i++){
				retptr->elements[i] = 0;
				if(i%(size+1) == 0)retptr->elements[i] = 1;
		}


		return retptr;
}
matrix* matrix_transpose(matrix* mtrx){
		matrix* temp = matrix_create(mtrx->y,mtrx->x);

		temp->elements[0] = mtrx->elements[0];
		temp->elements[temp->x*temp->y-1] = mtrx->elements[temp->x*temp->y-1];

		for(int i = 1; i < mtrx->x*mtrx->y-1; i++){

				temp->elements[i] = mtrx->elements[(i*mtrx->x)%((mtrx->x*mtrx->y)-1)];
		}
		matrix_print(temp);

		return temp;
}
matrix* matrix_append_right(matrix* mtrx1,matrix* mtrx2){
		if(mtrx1->y != mtrx2->y)return NULL;

		matrix_print(mtrx1);
		matrix_print(mtrx2);
		matrix* temp = matrix_create(mtrx1->x*2,mtrx1->y);

		int index = 0;
		while(index < temp->x*temp->y){
				static int index_1,index_2 = 0;

				for(int m1_x = index_1; m1_x < index_1+mtrx1->x; m1_x++){
						temp->elements[index] = mtrx1->elements[m1_x];
						index++;
				}
				index_1 += mtrx1->x;
				for(int m2_x = index_2; m2_x < index_2+mtrx2->x; m2_x++){
						temp->elements[index] = mtrx2->elements[m2_x];
						index++;
				}
				index_2 += mtrx2->x;
		}
		matrix_print(temp);

		return temp;
}
void matrix_print_2(matrix* mtrx1, matrix* mtrx2){
		int index = 0;
		while(index < mtrx1->x*mtrx1->y+mtrx2->x*mtrx2->y){
				static int index_1,index_2 = 0;

				for(int m1_x = index_1; m1_x < index_1+mtrx1->x; m1_x++){
						printf("%d ", mtrx1->elements[m1_x]);
						index++;
				}
				printf("  ");
				index_1 += mtrx1->x;
				for(int m2_x = index_2; m2_x < index_2+mtrx2->x; m2_x++){
						printf("%d ", mtrx2->elements[m2_x]);

						index++;
				}
				printf("\n");
				index_2 += mtrx2->x;
		}

}
