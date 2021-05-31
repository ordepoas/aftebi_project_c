#include <stdio.h>
#include <string.h>

int validaOpcao(int x) {

    int n;
    char buffer[10];

    do
    {
        printf("Qual a sua opção: ");
        fgets(buffer, 10, stdin);
        sscanf(buffer, "%d", &n);
        
    } while (n < 0 || n > x);

    return n;
}

int main()
{
    int opcao;

    opcao = validaOpcao(3);
    printf("%d\n", opcao);


    return 0;
}