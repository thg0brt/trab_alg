#include <stdio.h>
#include <string.h>

int permutacao_circular(char * base, char * perm_base, int tentativa){
	char temp[201], temp_;
	int i;
	temp_ = base[0];
	tentativa++;
	if(tentativa == strlen(base)){
		return -1;
	}else{	
		for(i=1; i<(strlen(base)); i++){
			temp[i-1] = base[i];
		}
		temp[strlen(base)-1] = temp_;
		if(strcmp(base, perm_base) == 0){
			return 0;
		}
		//printf("tentativa: %d -- Len base: %d -- base: %s - perm_base: %s - temp: %s\n", tentativa, (int)strlen(base)-1, base, perm_base, temp);
		if(strcmp(temp, perm_base) == 0){ 
			return tentativa;
		}else{
			return permutacao_circular(temp, perm_base, tentativa);
		}
	}
}

int main(){
    char base[201];
    char perm_base[201];
    int n, result, count=0;
    scanf("%d", &n);
    getchar();
    while(n--){
        gets(base);
        gets(perm_base);
        printf("Teste %d\n", ++count);
        result = permutacao_circular(base, perm_base, 0);
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
