#include <stdio.h>

int menu1() {

    int x;

    printf("(1)\t Opção 1\n");
    printf("(2)\t Opção 2\n");
    printf("\n");
    printf("Escolha uma opção: \n");
    scanf("%d", &x);

    return x;

}

int main(){

    int opcao;
    opcao = menu1();

    if(opcao == 1) {
        printf("Foi 1!!\n");
    } else if (opcao == 2) {
        printf("Foi 2!!\n");
    }
    

    return 0;
}