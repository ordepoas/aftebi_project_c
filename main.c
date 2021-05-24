# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "struct.c"

//----------------------------------------------------------------- DECLARAÇÃO DE FUNÇÕES
int menu1(Perfil *p);
int menu2(Perfil *p);
int menu3(Perfil *p, int x, int contarMensagens[]);
int validaOpcao(); 
int validaData(int dia, int mes, int ano);
Perfil criarPerfil(int *contaPerfil); 
void listarPerfil(Perfil *p, int counter); 
void escolherPerfil(Perfil *p, int counter, int contarMensagens[]); 
void publicarMensagem(Perfil *p, int x, int contarMensagens[]); 

//----------------------------------------------------------------- MAIN
int main() {

    Perfil p[MAX_USERS];
  
    while(menu1(p) != 0);

    return 0;
}

//----------------------------------------------------------------- MENUS
//1º menu de opções
int menu1(Perfil *p) {

    int opcao;

    printf("------------------------------------------\n");
    printf("(1)\tCriar um novo perfil\n");
    printf("(2)\tUtilizar um perfil existente\n");
    printf("\n");
    printf("(0)\tSair\n");
    printf("------------------------------------------\n");
    printf("\n");
    printf("Escolha uma das opções: ");
    
    opcao = validaOpcao();

        if(opcao == 1) {
        p[contaPerfil] = criarPerfil(&contaPerfil);
    } else if (opcao == 2) {
        listarPerfil(p, contaPerfil);
        menu2(p);
    }

    return opcao;
}  

//2º menu de opções
int menu2(Perfil *p) {

    int opcao;

    printf("------------------------------------------\n");
    printf("(1)\tVizualizar um dos perfis\n");
    printf("(2)\tVoltar atrás\n");
    printf("\n");
    printf("(0)\tSair\n");
    printf("------------------------------------------\n");
    printf("\n");
    printf("Escolha uma das opções: \n");
    
    opcao = validaOpcao();

    if(opcao == 1) {

        escolherPerfil(p, contaPerfil, contarMensagens);
    } else if (opcao == 2) {

        menu1(p);
    }

    exit(opcao);

    return opcao;
}  

//3º menu de opções
int menu3(Perfil *p, int x,int contarMensagens[]) {

    int opcao;

    printf("------------------------------------------\n");
    printf("(1)\tColocar uma mensagem no Mural\n");
    printf("(2)\tVoltar atrás\n");
    printf("\n");
    printf("(0)\tSair\n");
    printf("------------------------------------------\n");
    printf("\n");
    printf("Escolha uma das opções: \n");
    
    opcao = validaOpcao();

    if(opcao == 1) {
        publicarMensagem(p,x,contarMensagens);
    } else if (opcao == 2) {

        menu2(p);

    }

    exit(opcao);

    return opcao;
}  

//----------------------------------------------------------------- FUNÇÕES

//Função par validar a opção escolhida nos menus devolve 0, 1 ou 2
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

//Função para validar a data entrada -> devolve o valor 0 para inválida e 1 para válida
int validaData(int dia, int mes, int ano) //PRECISO VALIDAR COM DATA ATUAL
{
    //se o retorno da função for 0 a data não é válida se for 1 é válida
    if((dia > 0 && mes > 0 && ano >= 0) && (dia <= 31 && mes <=12))
    {

        if (mes = 2 && dia > 29 || mes > 12) {
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

//Cria perfil de utilizador
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

// lista os perfis existentes
void listarPerfil(Perfil *p, int counter){

    int i;

    printf("--------------------------- [Perfis existentes] ---------------------------\n");
    for(i=0; i < counter; i++) {

        printf("-> %s %s\n", p[i].nome,p[i].sobrenome);

    }

    menu2(p);
}

//seleciona um perfil e apresenta o mural
void escolherPerfil(Perfil *p, int counter, int contarMensagens[]){

    int i, j, x, z;

    printf("--------------------------- [Escolha um dos perfis abaixo] ---------------------------\n");
    for(i=0; i < counter; i++) {

        printf("(%d) - %s %s\n", i, p[i].nome,p[i].sobrenome);

    }

    scanf("%d", &x);

    printf("%s %s - %s\n", p[x].nome,p[x].sobrenome, p[x].email);
    printf("\n\tMensagens do Mural\n");

    if(strlen(p[x].mural[0].autor) == 0) {
        
        printf("---- Não há mensagens publicadas ----\n");

    } else {

        for (j = 0; j < contarMensagens[x]; j++) {

            printf("\t%s | %s\n", p[x].mural[j].autor,p[x].mural[j].texto);
        }
    }

    printf("\n");    
    menu3(p, x, contarMensagens);

}

//publica uma mensagem no mural
void publicarMensagem(Perfil *p, int x, int contarMensagens[]){



    printf("Deixe a sua Mensagem\n");
    printf("Nome:\n");
    fgets(p[x].mural[contarMensagens[x]].autor, MAX_LENGTH_50, stdin);
    printf("Mensagem: \n");
    fgets(p[x].mural[contarMensagens[x]].texto, MAX_LENGTH_200, stdin);
    printf("\n");

    (contarMensagens[x])++;    

    menu3(p, x, contarMensagens);
}