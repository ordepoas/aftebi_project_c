#include <stdio.h>

int contar[10] = {0};

void printContar(){

    for(int i = 0; i < 10; i++) {

        printf("%d\n", contar[i]);
    }
}

int main(){

    printContar();

    return 0;
}