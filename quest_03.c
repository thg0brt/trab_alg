#include <stdio.h>
#include <string.h>

#define sizearray 12
void append(char* s, char c){
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

void append_w_index(char *s, char c, int i){
    int len = strlen(s)-i;
    s[len] = c;
    s[len+1] = '\0';
}

void getName (char* name){
    int i, nameLength = strlen(name);
    char* temp[sizearray];
    int* index[sizearray];
    char* last_name[20];
    char* full_name[strlen(name)];
    memset(temp, '\0', sizeof(char)*strlen(temp));
    memset(last_name, '\0', sizeof(char)*strlen(last_name));
    for(i=0; i<nameLength; i++){
        if((int)name[i] >= 65 && (int)name[i] <= 90){
            append(temp, name[i]);
            append(temp, '.');
            index[((sizeof(index)/sizeof(int))-sizearray)+strlen(temp)-1] = i;
        }
    }
    for(i=index[(((sizeof(index)/sizeof(int))-sizearray)+strlen(temp))-1]; i<nameLength; i++){
        append(last_name, name[i]);
    }

    append_w_index(temp, '\0', 2);
    memset(full_name, '\0', sizeof(char)*strlen(full_name));
    strcat(full_name, last_name);
    append(full_name, ',');
    append(full_name, ' ');
    strcat(full_name, temp);
    printf("%s\n", full_name);
}

int main(){
    int n;
    char name[201];
    scanf("%d", &n);
    getchar();
    while(n--){
        gets(name);
        getName(name);
    }
    return 0;
}