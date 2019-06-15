#include <stdio.h>
#include <string.h>

int check(char* a, char* b, int index){
    int syzeA = strlen(a);
    int syzeB = strlen(b);
    int i;
    
    char temp[syzeB];
    
    if(index > syzeA){
        return 0;
    }

    for(i=index; i<(index+syzeB); i++){
        temp[i-index] = a[i];
        // printf("temp[%d] = a[%d]\n", i-index, i);
    }
    memset(&temp[syzeB], '\0', sizeof(char)*strlen(temp));
    
    if(!strcmp(temp, b)){
        return index;
    }else{
        return check(a, b, ++index);
    }
}

int main(void) {
    int n, result, i, count=0;
    char a[201], b[201], c[201], d[201];
    scanf("%d", &n);
    getchar();
    while(n--){
        gets(a);
        gets(b);
        printf("Teste %d\n", ++count);
        for(i=0; i<a[i]; i++) c[i] = tolower(a[i]);
        for(i=0; i<b[i]; i++) d[i] = tolower(b[i]);
        result = check(c, d, 0);
        if(!result){
            printf("%s não ocorre em %s.\n", b, a);
        }else{
            printf("%s ocorre na posição %d de %s.\n", b, result, a);
        }
    }
    return 0;
}