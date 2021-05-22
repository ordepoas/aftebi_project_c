# include <stdio.h>
# include <string.h>
# include "struct.c"

int contaPerfil = 0;


//----------------------------------------------------------------- DECLARAÇÃO DE CONSTANTES
# define MAX_USERS 10 //numero maximo de perfis
# define MAX_LENGTH_200 199 //tamanha maximo das mensagens do mural (incluido na estrutura Perfil)
# define MAX_LENGTH_50 49 //tamanho maximo do campo email (estrutura Perfil)
# define MAX_LENGTH_25 24 //tamanho maximo dos campos nome e sobrenome (estrutura Perfil)

//----------------------------------------------------------------- DECLARAÇÃO DE FUNÇÕES
int menu1();
int menu2();
int menu3();
int validaOpcao();
int validaData(int dia, int mes, int ano);
Perfil criarPerfil(int *contaPerfil);
void listarPerfil();
void escolherPerfil();
void publicarMensagem();

//----------------------------------------------------------------- MAIN
int main() {

    Perfil p[MAX_USERS];
    menu1();



    return 0;
}

//----------------------------------------------------------------- MENUS
int menu1() {

    int opcao;

    printf("------------------------------------------\n");
    printf("(1)\tCriar um novo perfil\n");
    printf("(2)\tUtilizar um perfil existente\n");
    printf("\n");
    printf("(0)\tSair\n");
    printf("------------------------------------------\n");
    printf("\n");
    printf("Escolha uma das opções: \n");
    
    opcao = validaOpcao();

    if(opcao == 1) {
        criarPerfil(&contaPerfil);
        menu1();
    } else if (opcao == 2) {
        listarPerfil();
    }

    return opcao;
}  

//----------------------------------------------------------------- FUNÇÕES
//Função par validar a opção escolhida no menu devolve 0, 1 ou 2
int validaOpcao() {

    int n;

    while (1) {

        scanf(" %d", &n);
        getchar();
        if(n != 0 && n != 1 && n != 2) {

            printf("Opção inválida\n");
        }

        return n;
    }
}

//Função para validar a data entrada -> 0 inválida 1 válida
int validaData(int dia, int mes, int ano)
{
    //se o retorno da função for 0 a data não é válida se for 1 é válida
    if((dia > 0 && mes > 0 && ano >= 0) && (dia <= 31 && mes <=12))
    {

        if (mes = 2 && dia > 29) {
                return 0;
        } else if (dia == 29)
            {
                if(ano % 4 != 0){
                    return 0;;
                } else if (ano % 100 != 0 ) {
                    return 1;
                } else if (ano % 400 == 0) {
                    return 1;
                } else {
                    return 0;
                }
            }
    }

    if ((mes = 4 || mes == 6 || mes == 9 || mes == 11) && (dia >30))
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}

Perfil criarPerfil(int *contaPerfil){

    Perfil p;
    char buffer[MAX_LENGTH_50];

    int dia, mes, ano;

    printf("Nome? \n");
    fgets(p.nome,MAX_LENGTH_25,stdin);
    p.nome[strlen(p.nome)-1] = '\0';
    printf("Sobrenome? \n");
    fgets(p.sobrenome,MAX_LENGTH_25,stdin);
    p.sobrenome[strlen(p.sobrenome)-1] = '\0';
    printf("Data de nascimento?\n");
    
    do {
        printf("Dia: ");
        fgets(buffer, MAX_LENGTH_50, stdin);
        sscanf(buffer," %d", &dia);
        printf("Mês: ");
        fgets(buffer, MAX_LENGTH_50, stdin);
        sscanf(buffer," %d", &mes);
        printf("Ano: ");
        fgets(buffer, MAX_LENGTH_50, stdin);
        sscanf(buffer," %d", &ano);
        
        if(validaData(dia, mes, ano) == 0) {
            printf("Data inválida\n");
        } else {
            p.dataNascimento.dia = dia;
            p.dataNascimento.mes = mes;
            p.dataNascimento.ano = ano;
        }

    } while ((validaData(dia, mes, ano) == 0));

    printf("\nemail? \n");
    fgets(p.email,MAX_LENGTH_50,stdin);
    p.email[strlen(p.email)-1] = '\0';
    printf("\nPerfil criado com sucesso!! \n");
    printf("\n");

    (*contaPerfil)++;
    return p;
    
}
void listarPerfil(){
    printf("Listar Perfil\n");
}

void escolherPerfil(){
    printf("Escolher Perfil\n");
}

void publicarMensagem(){
    printf("Publica Mensagem\n");
}