#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_P 3
#define MAX_C 25

typedef struct s_pessoa
{
    char nome[MAX_C];
    char sobrenome[MAX_C];
} Pessoa;

Pessoa addPessoa()
{

    Pessoa p;

    printf("Nome: ");
    fgets(p.nome, MAX_C, stdin);
    printf("Sobrenome: ");
    fgets(p.sobrenome, MAX_C, stdin);

    return p;

}

void deletePessoa(int n)
{

}

int main()
{

    Pessoa p[MAX_P];

    for (int i; i < MAX_P; i++)
    {
        p[i] = addPessoa();
    }

    for (int i = 0; i < MAX_P; i++)
    {
        printf("%d -> %s %s", i, p[i].nome, p[i].sobrenome);
    }

    printf("Escolha um perfil para remover: \n");
    int n;
    scanf("%d", &n);

    for (int i = n; i < MAX_P; i++) {

        p[i] = p[i+1];

    }

    for (int i = 0; i < MAX_P; i++)
    {
        printf("%d -> %s %s", i, p[i].nome, p[i].sobrenome);
    }


    return 0;
}
