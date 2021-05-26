#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_student 
{
   char nome[20];
   int idade;

} Student;

Student criaStudent(int *a) {

    Student s;
    printf("Nome: ");
    scanf("%s", s.nome);
    printf("Idade: ");
    scanf("%d", &s.idade);

    (*a)++;

    return s;

}


int main() {

    int studentCounter = 0;

    Student s[5];
    /*
    strcpy(s[1].nome, "João");
    s[1].idade = 29;
    strcpy(s[2].nome, "Maria");
    s[2].idade = 14;
    */

   s[studentCounter] = criaStudent(&studentCounter);
   s[studentCounter] = criaStudent(&studentCounter);


    FILE *backup;
    backup = fopen("backup.txt", "w");

    for(int i = 0; i < studentCounter; i++) {

        fprintf(backup, "%s %d", s[i].nome, s[i].idade);
    }

    FILE *counter;
    counter = fopen("counter.txt", "w");

    fprintf(counter, "%d", studentCounter);

    return 0;
}
