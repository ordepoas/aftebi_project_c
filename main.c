# include "headers.h"

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

    printf("\n\t\t------------------------------------------\n");
    printf("\t\t(1)\tCriar um novo perfil\n");
    printf("\t\t(2)\tUtilizar um perfil existente\n");
    printf("\n");
    printf("\t\t(0)\tSair\n");
    printf("\t\t------------------------------------------\n");
    printf("\n");
    printf("\t\tEscolha uma das opções: ");
    
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

    printf("\t\t------------------------------------------\n");
    printf("\t\t(1)\tVizualizar um dos perfis\n");
    printf("\t\t(2)\tVoltar atrás\n");
    printf("\n");
    printf("\t\t(0)\tSair\n");
    printf("\t\t------------------------------------------\n");
    printf("\n");
    printf("\t\tEscolha uma das opções: ");
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

    printf("\t\t------------------------------------------\n");
    printf("\t\t(1)\tColocar uma mensagem no Mural\n");
    printf("\t\t(2)\tVoltar atrás\n");
    printf("\n");
    printf("\t\t(0)\tSair\n");
    printf("\t\t------------------------------------------\n");
    printf("\n");
    printf("\t\tEscolha uma das opções: ");
    printf("\n\t\t");

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

        scanf("%d", &n);
        getchar();
        if(n != 0 && n != 1 && n != 2) {

            printf("\t\tOpção inválida\n\t\t");
        }

        return n;
    }
}

//Função para validar a data entrada -> devolve o valor 0 para inválida e 1 para válida
int validaData(int dia, int mes, int ano) 
{   

    //validar a data em relação à data atual (dia, mes e ano < hoje)

    time_t rawDate; // varialvel para receber a data atual em segundos --> informação retirada do site stackoverflow
    struct tm *todayDate; //struct em time.h --> informação retirada do site stackoverflow
    time(&rawDate); //data atual em segundos
    todayDate = localtime (&rawDate); //--> informação retirada do site stackoverflow

    if((ano+18) > (todayDate->tm_year+1900) || ((ano+18) == (todayDate->tm_year+1900)) && (mes > (todayDate->tm_mon)) || ((ano+18) == (todayDate->tm_year+1900)) && (mes == (todayDate->tm_mon)) && (dia > (todayDate->tm_mday))) {

        return 3;
        
    } else if ((dia > 0 && mes > 0 && ano >= 0) && (dia <= 31 && mes <=12)) {

        if (mes = 2 && dia > 29 || mes > 12) {
                return 0;
        } else if (dia == 29){
            
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

    if ((mes = 4 || mes == 6 || mes == 9 || mes == 11) && (dia >30)) {

        return 0;
    } else {

        return 1;
    }
}

//Cria perfil de utilizador
Perfil criarPerfil(int *contaPerfil){

    Perfil p;
    char buffer[MAX_LENGTH_50];

    int dia, mes, ano;

    printf("\n\t\tNome? ");
    fgets(p.nome,MAX_LENGTH_25-1,stdin);
    p.nome[strlen(p.nome)-1] = '\0';
    printf("\t\tSobrenome? ");
    fgets(p.sobrenome,MAX_LENGTH_25-1,stdin);
    p.sobrenome[strlen(p.sobrenome)-1] = '\0';
    printf("\t\tData de nascimento?\n");
    
    do {
        printf("\t\tDia: ");
        fgets(buffer, MAX_LENGTH_50-1, stdin);
        sscanf(buffer," %d", &dia);
        printf("\t\tMês: ");
        fgets(buffer, MAX_LENGTH_50-1, stdin);
        sscanf(buffer," %d", &mes);
        printf("\t\tAno: ");
        fgets(buffer, MAX_LENGTH_50-1, stdin);
        sscanf(buffer," %d", &ano);
        
        if(validaData(dia, mes, ano) == 3) {

            printf("\t\tData inválida\n");
            printf("\t\tNão tem 18 anos!\n");

        } else if (validaData(dia, mes, ano) == 0) {
            printf("\t\tData inválida\n");
        } else {
            p.dataNascimento.dia = dia;
            p.dataNascimento.mes = mes;
            p.dataNascimento.ano = ano;
        }

    } while ((validaData(dia, mes, ano) == 0) || (validaData(dia, mes, ano) == 3));

    printf("\n\t\temail? \n\t\t");
    fgets(p.email,MAX_LENGTH_50-1,stdin);
    p.email[strlen(p.email)-1] = '\0';
    printf("\n\t\t-------------------------------\n");
    printf("\t\t| Perfil criado com sucesso!! |\n");
    printf("\t\t-------------------------------\n");
    printf("\n");

    (*contaPerfil)++;

    return p;
    
}

// lista os perfis existentes
void listarPerfil(Perfil *p, int counter){

    int i;

    printf("\t\t--------------------------- [Perfis existentes] ---------------------------\n\n");
    for(i=0; i < counter; i++) {

        printf("\t\t-> %s %s\n", p[i].nome,p[i].sobrenome);
        
    }
    printf("\n");

    menu2(p);
}

//seleciona um perfil e apresenta o mural
void escolherPerfil(Perfil *p, int counter, int contarMensagens[]){

    int i, j, x, z;

    printf("\t\t--------------------------- [Escolha um dos perfis abaixo] ---------------------------\n\n");
    for(i=0; i < counter; i++) {

        printf("\t\t(%d) - %s %s \n", i, p[i].nome,p[i].sobrenome);

    }
    printf("\t\tIndique a sua opção: \n");

    scanf(" %d", &x);

    printf("\t\t%s %s - %s\n", p[x].nome,p[x].sobrenome, p[x].email);
    printf("\n\t\t\tMensagens do Mural\n\n");

    if(strlen(p[x].mural[0].autor) == 0) {
        
        printf("\t\t\t---- Não há mensagens publicadas ----\n");

    } else {

        for (j = 0; j < contarMensagens[x]; j++) {

            printf("\t\t\tAutor: %s | Mensagem: %s\n", p[x].mural[j].autor,p[x].mural[j].texto);
        }
    }

    printf("\n");    
    menu3(p, x, contarMensagens);

}

//publica uma mensagem no mural
void publicarMensagem(Perfil *p, int x, int contarMensagens[]){



    printf("\t\tDeixe a sua Mensagem\n");
    printf("\t\tNome: ");
    fgets(p[x].mural[contarMensagens[x]].autor, MAX_LENGTH_50, stdin);
    p[x].mural[contarMensagens[x]].autor[strlen(p[x].mural[contarMensagens[x]].autor)-1] = '\0';
    printf("\t\tMensagem: ");
    fgets(p[x].mural[contarMensagens[x]].texto, MAX_LENGTH_200, stdin);
    p[x].mural[contarMensagens[x]].texto[strlen(p[x].mural[contarMensagens[x]].texto)-1] = '\0';
    printf("\n");

    (contarMensagens[x])++;    

    menu3(p, x, contarMensagens);
}