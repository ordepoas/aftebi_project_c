//---- Estrutura da data a usar na estrutura perfil
typedef struct {

    int dia;
    int mes;
    int ano;
} Data;

//---- Estrutura do Mural a incluir na estrutura perfil
typedef struct {

    char autor[50];
    char texto[200];
} Mural;

// ---- Estrutura do perfil
typedef struct Perfis{

    char nome[25];
    char sobrenome[25];
    Data dataNascimento;
    char email[50];
    Mural mural[50];

} Perfil;