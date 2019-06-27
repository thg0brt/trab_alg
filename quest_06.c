#include <stdio.h>
#include <string.h>
int main(){
	int n, A, B, c=1, x=0, countX; //declaração de variaveis inteiras
	float result; //declaracao de variavel float
	scanf("%d", &n); //le a quantidade de equacões
	float vetX[n]; //declaração de um vetor de float
	for(int a=0; a<n;a++) vetX[a]=-1; //seta todos os valores de vetX como -1
	
	while(n){ //repete o codigo enquanto n seja maior que 0
		scanf("%d", &B); //le o termo independente 
		countX=0; //seta countX como 0
		result=0; //seta result como 0
		
		for(int i=0; i<c; i++){ //repete o codigo enquanto i seja menor que c
			scanf("%d", &A); //le os elementos do sistema
			if (c==1) vetX[x] = B/(float)A; //caso c==0, X1 = termo independente / primeiro elemento da equação
			
			else if (c>1){ //caso c>1, segue para a proxima equação
				if(i==0) result=(A*vetX[0]); //caso i==0, calcula o resultado da primeira parte da equação X1
				
				else if(vetX[i]!=-1) result=result+(A*vetX[countX]); //caso Xi!= -1, calcula o resultado da proxima parte da equação Xi
				
				else if(vetX[i]==-1) vetX[x]=(result-B)/-A; //caso Xi==-1, calcula o resultado do ultimo X do sistema;
			}	
			countX++; //aumenta 1 ao countX
		}
		
		printf("X%d = %.4f\n", c, vetX[x]);//imprime o resultado do X atual
		x++; //adiciona 1 ao x
		c++; //aumenta 1 ao c
		n--; //decremente o n
	}
}
