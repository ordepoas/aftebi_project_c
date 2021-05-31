# include "headers.h"

//----------------------------------------------------------------- MAIN
int main() {

    system("clear");

    Perfil p[MAX_USERS]; //define o array de estruturas que vão receber os perfis
    
    restore(p); 

    while(menu1(p) != 0);


    return 0;
}

//----------------------------------------------------------------- MENUS

//1º menu de opções
int menu1(Perfil *p) {

    int opcao, x;

    printf("\n\t\t------------------------------------------\n");
    printf("\t\t(1)\tCriar um novo perfil\n");
    printf("\t\t(2)\tUtilizar um perfil existente\n");
    printf("\n");
    printf("\t\t(0)\tSair\n");
    printf("\t\t------------------------------------------\n");
    printf("\n");
    printf("\t\tEscolha uma das opções: ");
    
    opcao = validaOpcao(2);

        if(opcao == 1) {
        p[contaPerfil] = criarPerfil(&contaPerfil); //recebe o perfil criado na função
    } else if (opcao == 2) {
        x = listarPerfil(p, contaPerfil);
        menu2(p, x);

    } else if (opcao == 0) {

        backup(p, contaPerfil);

    }

    return opcao;
}  

//2º menu de opções
int menu2(Perfil *p, int x) {

    int opcao;

    printf("\t\t------------------------------------------\n");
    printf("\t\t(1)\tVizualizar um dos perfis\n");
    printf("\t\t(2)\tVoltar atrás\n");
    printf("\n");
    printf("\t\t(0)\tSair\n");
    printf("\t\t------------------------------------------\n");
    printf("\n");
    printf("\t\tEscolha uma das opções: ");
    opcao = validaOpcao(2);

    if(opcao == 1) {

        escolherPerfil(p, contaPerfil, x);

    } else if (opcao == 2) {

        menu1(p);

    } else if(opcao == 0) {

        backup(p, contaPerfil);
        exit(opcao);
    }

    return opcao;
}  

//3º menu de opções
int menu3(Perfil *p, int x, int y) {

    int opcao;

    printf("\t\t------------------------------------------\n");
    printf("\t\t(1)\tColocar uma mensagem no Mural\n");
    printf("\t\t(2)\tVoltar atrás\n");
    printf("\t\t(3)\tDeixar gosto numa mensagem\n");
    if(x == y) {
    printf("\t\t(4)\tApagar uma mensagem do mural\n");
    }
    printf("\n");
    printf("\t\t(0)\tSair\n");
    printf("\t\t------------------------------------------\n");
    printf("\n");
    printf("\t\tEscolha uma das opções: ");

    opcao = validaOpcao(4);

    if(opcao == 1) {
        publicarMensagem(p, x, y);
    } else if (opcao == 2) {

        menu2(p, y);
    } else if(opcao == 3) {

        deixaGosto(p, x, y);
        menu3(p, x, y);

    } else if(opcao == 4) {

        apagaMensagem(p, x, y);
        menu3(p, x, y);

    } else if(opcao == 0) {

        backup(p, contaPerfil);
        exit(opcao);
    }

    return opcao;
}  

//----------------------------------------------------------------- FUNÇÕES
//Backup para ficheiro
void backup(Perfil *p, int a) {

    int y;

    printf("\n\t\tQuer fazer backup dos perfis desta sessão? \n");
    printf("\t\tEscolha (1) para backup ou (2) para continuar: ");


    do {

        scanf("%d", &y);

        if(y != 1 && y != 2) {
            printf("\t\tOpção inválida!!\n\t\t");
        }

    } while (y != 1 && y != 2);

    if(y == 1) {
        //---- Backup----

        FILE *counter;
        counter = fopen("counter.txt", "w+");
        fprintf(counter, "%d ", contaPerfil);
        fclose(counter);
        
        //código retirado do stackoverflow e ajustado
        FILE* data;
        
        if ( (data = fopen("data.bin", "wb")) == NULL ) {
            printf("Error opening file\n");
            //return 1;   
        }

        fwrite(p, sizeof(Perfil) * contaPerfil, 1, data);
        fclose(data);

    }

    exit(0);
}

//Restore de ficheiro
void restore(Perfil *p) {

    int y;

    printf("\n\t\tQuer restaurar os perfis da sessão anterior? \n");
    printf("\t\tEscolha (1) para restaurar ou (2) para continuar: ");


    do {

        scanf("%d", &y);

        if(y != 1 && y != 2) {
            printf("\t\tOpção inválida!!\n\t\t");
        }

    } while (y != 1 && y != 2);

    if(y == 1) {

        //---- Restore----
        FILE *counter;
        counter = fopen("counter.txt", "r");
        char buffer[MAX_LENGTH_25];

        fgets(buffer, MAX_LENGTH_25, counter);
        sscanf(buffer, "%d", &contaPerfil);

        fclose(counter);

        //código retirado do stackoverflow e ajustado 
        FILE* data;
        if ((data = fopen("data.bin", "rb")) == NULL){

            printf("Error opening file\n");

        }

        for (int i = 0; i < contaPerfil; i++) {

            fread(p, sizeof(Perfil) * contaPerfil, 1, data);
        }
        fclose(data);

    }
}

//Função par validar a opção escolhida nos menus e devolve a opcao escolhida, o parametro são o numero de opções do menu;
int validaOpcao(int x) {

    int n;

    do {

        char buffer[2];
        scanf("%d", &n);
        getchar();
        printf("\t\t");


    } while (n < 0 || n > x);

    return n;
}

//Função para validar a data entrada -> devolve o valor 0 para inválida e 1 para válida
int validaData(int dia, int mes, int ano) 
{   

    //validar a data em relação à data atual (dia, mes e ano < hoje)

    time_t rawDate; // varialvel para receber a data atual em segundos --> informação retirada do site stackoverflow
    struct tm *todayDate; //struct em time.h --> informação retirada do site stackoverflow
    time(&rawDate); //data atual em segundos
    todayDate = localtime (&rawDate); //--> informação retirada do site stackoverflow

    if((ano > (todayDate->tm_year+1900)) || ((ano == (todayDate->tm_year+1900)) && (mes > (todayDate->tm_mon))) || ((ano == (todayDate->tm_year+1900)) && (mes == (todayDate->tm_mon)) && (dia > (todayDate->tm_mday)))) {

        return 0;
        
    } else if ((dia > 0 && mes > 0 && ano >= 0) && (dia <= 31 && mes <=12)) {

        if (mes = 2 && dia > 29 || mes > 12) {

                return 0;

        } else if (dia == 29){
            
            if(ano % 4 != 0){

                return 0;

            } else if (ano % 100 != 0 ) {

                return 1;

            } else if (ano % 400 == 0) {

                return 1;

            } else {

                return 0;
            }
        }
    }

    if(mes > 12 || dia > 31) {

        return 0;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia > 30)) {

        return 0;

    } else {

        return 1;
    }
}

// Validar caracter "@" para o campo email
int checkCaracter(char *a) {
    //if a contém b
    if (strstr(a, "@")) {

        return 1;
    }
    
    printf("\t\tEmail inválido\n");

    return 0;

}

//Validar se o comprimento da String é maior que 1 a usar na publicação de mensagens
int checkString(char *a) {
    if(strlen(a) == 0) {

        printf("\t\tIntroduza algum texto!!\n");
    }
    return strlen(a);
}

//Calcula idade
int calculateAge(int dia, int mes, int ano) {
    //Informação retirada do site stackoverflow
    time_t rawDate; // varialvel para receber a data atual em segundos --> informação retirada do site stackoverflow
    struct tm *todayDate; //struct em time.h --> informação retirada do site stackoverflow
    time(&rawDate); //data atual em segundos
    todayDate = localtime (&rawDate); //--> informação retirada do site stackoverflow

    int idade;

    if(mes > todayDate->tm_mon) {

        idade = todayDate->tm_year+1900-1-ano;

    } else if (mes = todayDate->tm_mon && dia > todayDate->tm_mday) {

        idade = todayDate->tm_year+1900-1-ano;

    } else {

        idade = todayDate->tm_year+1900-ano;

    }
    
    return idade;
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

    printf("\t\tLocalidade? ");
    fgets(p.localidade,MAX_LENGTH_25-1,stdin);
    p.localidade[strlen(p.localidade)-1] = '\0';

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
        
        if (validaData(dia, mes, ano) == 0) {
            printf("\t\tData inválida\n");
        } else {
            p.dataNascimento.dia = dia;
            p.dataNascimento.mes = mes;
            p.dataNascimento.ano = ano;
        }

    } while (validaData(dia, mes, ano) == 0);

    do {
        printf("\t\temail? ");
        fgets(p.email,MAX_LENGTH_50-1,stdin);
        p.email[strlen(p.email)-1] = '\0';
    } while (checkCaracter(p.email) == 0);

    printf("\n\n\t\t---- Dados para login ----\n");
    printf("\t\tUsername: ");
    fgets(p.login.username, MAX_LENGTH_25, stdin);
    p.login.username[strlen(p.login.username)-1] = '\0';

    printf("\t\tPassword: ");
    fgets(p.login.password, MAX_LENGTH_25, stdin);
    p.login.password[strlen(p.login.password)-1] = '\0';

    system("clear");

    printf("\n\n\t\t-------------------------------\n");
    printf("\t\t| Perfil criado com sucesso!! |\n");
    printf("\t\t-------------------------------\n");
    printf("\n");

    p.contaMsg = 0;

    (*contaPerfil)++;

    return p;
    
}

// lista os perfis existentes
int listarPerfil(Perfil *p, int counter){
    system("clear");
    char buffer[5];
    int i, x, y;

    printf("\n\t\t------------------- [Escolha um perfil para fazer login] -------------------\n\n");
    for(i=0; i < counter; i++) {

        printf("\t\t(%d) %s %s de %s\n", i, p[i].nome,p[i].sobrenome, p[i].localidade);
        
    }
    printf("\n");
    printf("\t\tIndique a sua opção: ");

    x = validaOpcao(i);

    /*
    do {
        fgets(buffer, 5, stdin);
        sscanf(buffer, "%d", &x);
    } while(x < 0 || x > i);
    */
    y = login(p, x);

    //menu2(p);
    return y;
}

//seleciona um perfil e apresenta o mural
void escolherPerfil(Perfil *p, int counter, int y){

    int i, j, x, z;

    printf("\n\t\t----------------------- [Escolha um dos perfis abaixo] ---------------------\n\n");
    for(i=0; i < counter; i++) {

        printf("\t\t(%d) - %s %s, %d anos de %s - email: %s\n", i, p[i].nome,p[i].sobrenome, calculateAge(p[i].dataNascimento.dia, p[i].dataNascimento.mes, p[i].dataNascimento.ano), p[i].localidade, p[i].email);

    }
    printf("\n\n\t\tIndique a sua opção: ");

    scanf("%d", &x);

    printf("\n\t\t%s %s | %d anos | %s | %s\n", p[x].nome,p[x].sobrenome, calculateAge(p[x].dataNascimento.dia, p[x].dataNascimento.mes, p[x].dataNascimento.ano), p[x].localidade, p[x].email);
    printf("\n\t\t\tMensagens do Mural\n\n");

    if(p[x].contaMsg == 0) {
        
        printf("\t\t\t---- Não há mensagens publicadas ----\n");

    } else {

        for (j = 0; j < p[x].contaMsg; j++) {

            printf("\t\t\tAutor: %s | Mensagem: %s | Gosto: %d\n", p[x].mural[j].autor,p[x].mural[j].texto,p[x].mural[j].contaGostos);
        }
    }

    printf("\n");    
    menu3(p, x, y);

}

//publica uma mensagem no mural
void publicarMensagem(Perfil *p, int x, int y){

    printf("\n\t\tDeixe a sua Mensagem\n");

    /*
    do {
        printf("\t\tNome: ");
        fgets(p[x].mural[p[x].contaMsg].autor, MAX_LENGTH_50, stdin);
        p[x].mural[p[x].contaMsg].autor[strlen(p[x].mural[p[x].contaMsg].autor)-1] = '\0';
    } while (checkString(p[x].mural[p[x].contaMsg].autor) == 0);
    */

    strcpy(p[x].mural[p[x].contaMsg].autor, p[y].nome);

    do {
        printf("\t\tMensagem: ");
        fgets(p[x].mural[p[x].contaMsg].texto, MAX_LENGTH_200, stdin);
        p[x].mural[p[x].contaMsg].texto[strlen(p[x].mural[p[x].contaMsg].texto)-1] = '\0';

    } while (checkString(p[x].mural[p[x].contaMsg].texto) == 0);

    printf("\n");
    
    p[x].mural[p[x].contaMsg].contaGostos = 0;   

    p[x].contaMsg++;

    system("clear");

    printf("\n\t\t%s %s | %d anos | %s | %s\n", p[x].nome,p[x].sobrenome, calculateAge(p[x].dataNascimento.dia, p[x].dataNascimento.mes, p[x].dataNascimento.ano), p[x].localidade, p[x].email);
    printf("\n\t\t\tMensagens do Mural\n\n");

    if(p[x].contaMsg == 0) {
        
        printf("\t\t\t---- Não há mensagens publicadas ----\n");

    } else {

        for (int j = 0; j < p[x].contaMsg; j++) {

            printf("\t\t\tAutor: %s | Mensagem: %s | Gosto: %d\n", p[x].mural[j].autor,p[x].mural[j].texto, p[x].mural[j].contaGostos);
        }
    }

    menu3(p, x, y);
}

//menu de login e validação
int login(Perfil *p, int x) {
    
    char buffer[MAX_LENGTH_25];

    char username_aux[MAX_LENGTH_25];
    char password_aux[MAX_LENGTH_25];

    int valLength, valString, res, c;

    printf("\t\t----- Login -----\n");
    printf("\t\tUsername: ");
    fgets(username_aux, MAX_LENGTH_25, stdin);
    username_aux[strlen(username_aux)-1] = '\0';
    printf("\t\tPassword: ");
    fgets(password_aux, MAX_LENGTH_25, stdin);
    password_aux[strlen(password_aux)-1] = '\0';

    if((strlen(username_aux) == strlen(p[x].login.username)) && (strlen(password_aux) == strlen(p[x].login.password))) {
        
        valLength = 0;

    } else {

        valLength = 1;
    }

    if((strstr(p[x].login.username, username_aux)) && (strstr(p[x].login.password, password_aux))) {
        
        valString = 0;

    } else {

        valString = 1;
    }

    res = valLength + valString;

    if(res == 0) {

        system("clear");
        printf("\n\t\tLogin efetuado com sucesso!!\n");

    } else {

        printf("\t\tPassword e/ou Username errados!!\n");
        printf("\t\tPrima (0) para voltar atrás ou (1) para tentar novamente\n");
                        
        do {

            printf("\t\t");
            fgets(buffer, MAX_LENGTH_25, stdin);
            sscanf(buffer, "%d", &c);

        } while (c != 1 && c != 0);

        switch(c) {

            case 1 :
                login(p,x);
                break;
            case 0 :
                menu1(p);

        }     
    }

    return x;


}

// apagar mensagens (permissão só para o utilizador proprietário do mural)
void apagaMensagem(Perfil *p, int x, int y) {

    int z, i;
    char buffer[10];

    printf("\t\tQual a mensagem que deseja apagar: \n");

    for (i = 0; i < p[y].contaMsg; i++) {

        printf("\t\t(%d) -> %s - %s", i, p[y].mural[i].autor, p[y].mural[i].texto);

    }

    printf("\n\t\tIndique a sua opção: ");

    z = validaOpcao(i);

    for (int i = z; i < p[y].contaMsg; i++) {

        strcpy(p[y].mural[i].autor, p[y].mural[i+1].autor);
        strcpy(p[y].mural[i].texto, p[y].mural[i+1].texto);

    }

    p[y].contaMsg--;

    printf("\n\t\tMensagem apagada com sucesso!!\n");

}

// deixar gosto nos comentários
void deixaGosto(Perfil *p, int x, int y) {

    int z, i;
    char buffer[10];

    printf("\t\tQual a mensagem que deseja deixar gosto: \n");

    for (i = 0; i < p[y].contaMsg; i++) {

        printf("\t\t(%d) -> %s - %s\n", i, p[y].mural[i].autor, p[y].mural[i].texto);

    }

    printf("\n\t\tIndique a sua opção: ");

    z = validaOpcao(i);

    p[y].mural[z].contaGostos++;

    system("clear");
    printf("\n\t\tO seu gosto foi publicado!!\n");

    printf("\n\t\t%s %s | %d anos | %s | %s\n", p[x].nome,p[x].sobrenome, calculateAge(p[x].dataNascimento.dia, p[x].dataNascimento.mes, p[x].dataNascimento.ano), p[x].localidade, p[x].email);
    printf("\n\t\t\tMensagens do Mural\n\n");

    if(p[x].contaMsg == 0) {
        
        printf("\t\t\t---- Não há mensagens publicadas ----\n");

    } else {

        for (int j = 0; j < p[x].contaMsg; j++) {

            printf("\t\t\tAutor: %s | Mensagem: %s | Gosto: %d\n", p[x].mural[j].autor,p[x].mural[j].texto, p[x].mural[j].contaGostos);
        }
    }


}