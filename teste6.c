#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_C 20

typedef struct s_pessoa {

    char nome[20];
    char username [20];
    char password [20];

} Pessoa;

int login(Pessoa p) {

    char buffer[MAX_C];

    char username_aux[MAX_C];
    char password_aux[MAX_C];

    int valLength, valString, res, c;

    printf("----- Login -----\n");
    printf("Username: ");
    fgets(username_aux, MAX_C, stdin);
    username_aux[strlen(username_aux)-1] = '\0';
    printf("Password: ");
    fgets(password_aux, MAX_C, stdin);
    password_aux[strlen(password_aux)-1] = '\0';


    if((strlen(username_aux) == strlen(p.username)) && (strlen(password_aux) == strlen(p.password))) {
        
        valLength = 0;

    } else {

        valLength = 1;
    }

    if((strstr(p.username, username_aux)) && (strstr(p.password, password_aux))) {
        
        valString = 0;

    } else {

        valString = 1;
    }

    res = valLength + valString;

    if(res == 0) {

        printf("Login efetuado com sucesso!!\n");

    } else {

        printf("Password e/ou Username errados!!\n");
        printf("prima (0) para sair ou (1) para tentar novamente\n");

        do {

            fgets(buffer, MAX_C, stdin);
            sscanf(buffer, "%d", &c);
            
            if(c == 1) {

                login(p);

            } else {

                exit(0);

            }     
            
        } while (c != 1 || c != 0);

    }

    return res;

}

int main()
{
    Pessoa a;
    strcpy(a.nome, "João");
    strcpy(a.username, "jpsaopedro");
    strcpy(a.password, "qwe123");
    
    Pessoa b;
    strcpy(b.nome, "Elsa");
    strcpy(b.username, "elsa");
    strcpy(b.password, "123qwe");

    login(b);  

    return 0;
}