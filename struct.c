#define MAX_LENGTH_25 24;
#define MAX_LENGTH_50 49;
#define MAX_LENGTH_200 199;


//---- Estrutura da data a usar na estrutura perfil
struct Data {

    int dia;
    int mes;
    int ano;
};

//---- Estrutura do Mural a incluir na estrutura perfil
struct Mural {

    char autor[50];
    char texto[200];
};

// ---- Estrutura do perfil
typedef struct Perfis{

    char nome[25];
    char sobrenome[25];
    struct Data dataNascimento;
    char email[50];
    struct Mural mural[50];

} Perfil;