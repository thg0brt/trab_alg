#include <stdio.h>

int main(){
	int n, x, resto, Mil, Cen, Des, Uni; //declaracao das variaveis inteiras
	float mil, cen, des, uni; //declaracao das variaveis float
	
	scanf ("%d", &x); //le o numeros de casos
	
	while(x){ //repete os procedimentos ate chegar no ultimo caso
		scanf("%d", &n);
		mil=n/1000; //armazena o valor da casa dos milhares
		resto = (n%1000); //armazena o resto para a casa das centenas
		
		cen=resto/100; //armazena o valor da casa dos milhares
		resto = resto%100; //armazena o resto para a casa das dezenas
		
		des=resto/10; //armazena o valor da casa das dezenas
		resto=resto%10;//armazena o resto para a casa das unidades
		
		uni=resto/1; //armazena o valor da casa das unidades
		
		Mil=(int)mil; //
		Cen=(int)cen; //transforma os valores em inteiro
		Des=(int)des; //
		Uni=(int)uni; //
		
		for(int m=0;m<Mil;m++) printf("M"); //MOSTRA OS MILHARES ---> M
		
		if(Cen==9) printf("CM"); //CONDICAO PARA O 900 ---> CM
	
		else if(Cen>=6 && Cen<=8){ //CONDICAO PARA VALOR ENTRE 600 E 800
			printf("D");
			Cen=Cen-5;
			for (int c=0; c<Cen; c++) printf("C");//
		}
		else if(Cen==5) printf("D"); //CONDICAO PARA O 500 ---> D
		
		else if(Cen==4) printf("CD"); //CONDICAO PARA O 400 ---> CD
		
		else for(int ce=0; ce<Cen;ce++) printf("C"); //MOSTRA AS CENTENAS ---> C
		
		
		if(Des==9) printf("XC"); //CONDICAO PARA O 90 ---> XC
		
		else if(Des>=6 && Des<=8){ //CONDICAO PARA VALOR ENTRE 60 E 80
			printf("L");
			Des=Des-5;
			for (int d=0; d<Des; d++) printf("X");
		}
		else if(Des==5) printf("L"); //CONDICAO PARA O 50 ---> L
		
		else if(Des==4) printf("XL"); //EXCLUSIVO PARA 40 ---> XL
		
		else for(int de=0; de<Des;de++) printf("X"); //MOSTRA AS DEZENAS ---> X
		
		
		if(Uni==9) printf ("IX"); //CONDICAO PARA O 9 --> IX
		
		else if(Uni>=6 && Uni<=8){ //CONDICAO PARA VALOR ENTRE 6 E 8
			printf("V"); 
			Uni=Uni-5; 
			for (int u=0; u<Uni; u++) printf("I");
		}
		else if(Uni==5)printf("V"); //CONDICAO PARA O 5 ---> V
		
		else if(Uni==4) printf("IV"); //CONDICAO PARA O 4 --> IV
		
		else for (int un=0; un<Uni; un++) printf("I");//MOSTRA AS UNIDADES ---> I
		printf("\n");
		x--;
	}
	
	return 0;
}
