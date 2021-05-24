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

    time_t time_raw_format;
    struct tm * ptr_time;

    time ( &time_raw_format );
    ptr_time = localtime ( &time_raw_format );
    //printf ("Current local time and date: %s\n", asctime(ptr_time));
    printf("%d-%d-%d\n", ptr_time->tm_mday, ptr_time->tm_mon, ptr_time->tm_year+1900);

    return 0;


    return 0;
}