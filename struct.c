//----------------------------------------------------------------- DECLARAÇÃO DE CONSTANTES
# define MAX_USERS 10 //numero maximo de perfis
# define MAX_LENGTH_200 199 //tamanha maximo das mensagens do mural (incluido na estrutura Perfil)
# define MAX_LENGTH_50 49 //tamanho maximo do campo email (estrutura Perfil)
# define MAX_LENGTH_25 24 //tamanho maximo dos campos nome e sobrenome (estrutura Perfil)
# define MAX_MSG 50 //tamanho maximo de mensagens permitidas por perfil

int contaPerfil = 0; //contador de perfis criados

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
    Mural mural[MAX_MSG];

} Perfil;