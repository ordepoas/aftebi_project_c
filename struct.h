#include "headers.h"

//----------------------------------------------------------------- DECLARAÇÃO DE ESTRUTURAS

//---- Estrutura da data a usar na estrutura perfil
typedef struct data {

    int dia;
    int mes;
    int ano;
} Data;

//---- Estrutura do Mural a incluir na estrutura perfil
typedef struct mural {

    char autor[50];
    char texto[200];
} Mural;

// ---- Estrutura do perfil
typedef struct perfil {

    char nome[25];
    char sobrenome[25];
    Data dataNascimento;
    char email[50];
    Mural mural[MAX_MSG];

} Perfil;