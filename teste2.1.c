#include <stdio.h>
#include <string.h>

int contar[10] = {0};

void printContar(){

    for(int i = 0; i < 10; i++) {

        printf("%d\n", contar[i]);
    }
}

int main(){

    //printContar();

    int len;
    char str[10];
    //strcpy(str, "João");

    len = strlen(str);

    printf("%d\n", len);

    return 0;
}