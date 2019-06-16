#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    int M[10][10];
    int m, n;
}Matriz;

double det(Matriz A, int size){
    if(size == 1){
        return A.M[0][0];
    }else if(size == 2){
        return (A.M[0][0]*A.M[1][1]) - (A.M[0][1]*A.M[1][0]);
    }else if(size == 3){
        // + a_(1,1)*a_(2,2)*a_(3,3) + a_(1,2)*a_(2,3)*a_(3,1) + a_(1,3)*a_(2,1)*a_(3,2)
        // - a_(1,3)*a_(2,2)*a_(3,1) - a_(1,1)*a_(2,3)*a_(3,2) - a_(1,2)*a_(2,1)*a_(3,3)
        return (A.M[0][0] * A.M[1][1] * A.M[2][2] + A.M[0][1]*A.M[1][2]*A.M[2][0] + A.M[0][2]*A.M[1][0]*A.M[2][1] 
        - A.M[0][2]*A.M[1][1]*A.M[2][0] - A.M[0][0]*A.M[1][2]*A.M[2][1] - A.M[0][1]*A.M[1][0]*A.M[2][2]);
    }else if(size >= 4){
        double det_of = 0;
        Matriz small;
        small.m = size-1;
        small.n = size-1;

        int i, j, k;
        int i_, j_;

        for (i=0; i<size; i++){
            if (A.M[0][i] == 0) continue;

            // get the matrix 3x3 outta the greater matrix
            i_ = 1;
            for ( j=0; j<size-1; j++ ){
                j_ = 0;
                for ( k=0; k<size-1; k++ ){
                    if ( i == j_ ) j_++;
                    small.M[j][k] = A.M[i_][j_];
                    j_++;
                }
                i_++;
            }
            det_of += A.M[0][i] * det(small, small.m) * pow(-1, i);
        }
        return det_of;
    }
}

void scanMat(Matriz *A, int l){
	int i, j;
	A->m = l;
	A->n = l;
	for (i = 0; i < l; i++)
		for (j = 0; j < l; j++)
			scanf("%d", &A->M[i][j]);
}

void printMat(Matriz A){
	int i, j;
	for (i = 0; i < A.m; i++){
		printf("| ");
		for (j = 0; j < A.n; j++)
			printf("%2d ", A.M[i][j]);
		printf("|\n");
	}
}

void calculaMat(Matriz A, char* fun){
    if(!strcmp(fun, "det")){
        printf("%.4lf\n", det(A, A.m));
    }
}

int main(){
    int n, count=0;
    Matriz mat;
    scanf("%d", &n);
    while(n>0 && n<=10){
        scanMat(&mat, n);
        // printMat(mat);
        printf("Caso %d\n", ++count);
        calculaMat(mat, "det");
        scanf("%d", &n);
    }
    
    return 0;
}