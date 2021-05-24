#include <stdio.h>
#include <string.h>
#include <time.h>

int contar[10] = {0};

void printContar(){

    for(int i = 0; i < 10; i++) {

        printf("%d\n", contar[i]);
    }
}

int main(){

    time_t current_time;
    printf("%d\n", time());

    return 0;
}