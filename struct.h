//----------------------------------------------------------------- DECLARAÇÃO DE CONSTANTES
# define MAX_USERS 10 //numero maximo de perfis
# define MAX_LENGTH_200 200 //tamanha maximo das mensagens do mural (incluido na estrutura Perfil)
# define MAX_LENGTH_50 50 //tamanho maximo do campo email (estrutura Perfil)
# define MAX_LENGTH_25 25 //tamanho maximo dos campos nome e sobrenome (estrutura Perfil)
# define MAX_MSG 50 //tamanho maximo de mensagens permitidas por perfil

int contaPerfil = 0; //contador de perfis criados
//int contarMensagens [MAX_USERS] = {0};


//----------------------------------------------------------------- DECLARAÇÃO DE ESTRUTURAS

//---- Estrutura da data a usar na estrutura perfil
typedef struct s_data {

    int dia;
    int mes;
    int ano;
} Data;

//---- Estrutura do Mural a incluir na estrutura perfil
typedef struct s_mural {

    char autor[50];
    char texto[200];
    int contaGostos;
} Mural;

//---- Estrutura do login
typedef struct s_login {
    char username[25];
    char password[25];
} Login;

// ---- Estrutura do perfil
typedef struct s_perfil {

    char nome[25];
    char sobrenome[25];
    Data dataNascimento;
    char email[50];
    char localidade[50];
    Mural mural[MAX_MSG];
    int contaMsg;
    Login login;

} Perfil;
