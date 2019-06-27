#include <stdio.h>
#include <string.h>

/*
	@params       @action
	base**       | Recebe a palavra base (recursiva)
	perm_base*   | Recebe a palavra permutada da vez 
	tentativa**  | Número da iteração atual

	* Não variável
	** Variável
 */
int permutacao_circular(char * base, char * perm_base, int tentativa){
	char temp[strlen(base)], temp_; // Cria uma cadeia que receberá a rotação da base e uma que receberá a primeira letra para inseri-lá ao final
	int i;
	temp_ = base[0]; // Armazena o primeiro caracter da palavra na váriavel temp_
	tentativa++;
	if(tentativa == strlen(base)){
		/* Caso o número de iterações chegue a se igualar com a quantidade
		   de caracteres da palavra significa que ela não pode ser obtida
		   a partir da permutação circular então a função retorna -1*/
		return -1;
	}else{	
		for(i=1; i<(strlen(base)); i++){ 
			/*
					   0 1 2 3
				base = A B C D
				temp = B C D _

				Faz a temp receber todos os caracteres exceto o primeiro, mas
				uma posição anterior
			 */
			temp[i-1] = base[i];
		}
		temp[strlen(base)-1] = temp_; /* Insere agora o primeiro caracter no final
				temp_ = A
				temp = B C D _ <- temp_

					   0 1 2 3	
				temp = B C D A
		*/ 
		memset(&temp[strlen(base)], '\0', sizeof(char)*strlen(temp)); // Limpa o excedente, evitando lixo de memória (provavelmente caso específico a máquina, mas resolvi previnir)
		if(strcmp(base, perm_base) == 0){
			/*
				Caso base e sua permutação sejam iguais
							
							0 1 2 3
				base =      A B C D 
				perm_base = A B C D

				a função retorna o valor 0
			*/
			return 0;
		}
		if(strcmp(temp, perm_base) == 0){
			/*
				Caso a váriavel que está mantendo a rotação atual seja igual a
				permutação desejada

							0 1 2 3
				temp = 		B C D A
				perm_base = B C D A

				significa que a cadeia base rotacionada x vezes pode chegar na cadeia
				perm_base, esse x é dado pela váriavel de controle de iterações

				a função retorna então tentativa
			*/ 
			return tentativa;
		}else{
			/*
				Caso nenhuma das condições anteriores seja satisfeita a função é 
				chamada novamente, contudo agora passando uma nova base, que é a
				base rotacionada x vezes

				1° iteração

							0 1 2 3 
				base = 		A B C D
				perm_base = C D B A
				___________________
				temp =      B C D A    -> passa a ser a nova base

				2° iteração

							0 1 2 3 
				base = 		B C D A
				perm_base = C D B A
				___________________
				temp =      C D B A    -> passa a ser a nova base

				3° iteração

							0 1 2 3 
				base = 		C D B A
				perm_base = C D B A 

				Na primeira iteração nenhuma condição é satisfeita, então ele retorna
				o valor da 2° iteração

				1° 		2°

				?   ->  x

				Na segunda iteração nenhuma condição é satisfeita, então ele retorna 
				o valor da 3° iteração

				1°		2°		3°

				?   ->  ?   ->  x

				Na terceira iteração a condição anterior é satisfeita, retornando o 
				valor de iterações ocorridas 

				1°		2°		3°

				3   ->  3   ->  3   
			
			*/
			return permutacao_circular(temp, perm_base, tentativa);
		}
	}
}

int main(){
    char base[201]; // Váriavel que receberá a cadeia base
    char perm_base[201]; // Váriavel que receberá a permutação desejada
    int n, result, count=0; // Váriaveis inteiras para manipulação
    scanf("%d", &n); // Lê quantos inputs serão dados
    getchar(); // Limpa o buffer
    while(n--){ // Enquanto n for maior que 0 executa os comandos abaixo
        scanf("%s", base); // Recebe a cadeia base
        scanf("%s", perm_base); // Recebe a cadeia permutada
        printf("Teste %d\n", ++count); // Imprime o número do teste atual
        result = permutacao_circular(base, perm_base, 0); // Faz a váriavel resultado receber o retorno da função de teste de permutação
        if(result == -1){
            printf("A cadeia %s não pode ser obtida a partir da cadeia %s por meio de deslocamentos\n", perm_base, base);
        }else if(result == 0){
            printf("As cadeias são iguais.\n");
        }else if(result > 0){
            printf("A cadeia %s pode ser obtida de %s após %d deslocamentos.\n", perm_base, base, result);
        }
        printf("\n");
    }
    return 0;
}