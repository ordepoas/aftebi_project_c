#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_L 25

struct Person 
{
    char f_name[256];
    char l_name[256];
    int age;
};

int main()
{
    char buffer[MAX_L];

    struct Person* people;
    int people_count;

    printf("How many people would you like to create: ");
    fgets(buffer, MAX_L, stdin);
    sscanf(buffer, "%i", &people_count);
    people = malloc(sizeof(struct Person) * people_count);  

    int n;
    for (n = 0; n < people_count; n++)
    {
        printf("Person %i's First Name: ", n);
        fgets(people[n].f_name, MAX_L, stdin);
        people[n].f_name[strlen(people[n].f_name)-1] = '\0';

        printf("Person %i's Last Name: ", n);
        fgets(people[n].l_name, MAX_L, stdin);
        people[n].l_name[strlen(people[n].l_name)-1] = '\0';

        printf("Person %i's Age: ", n);
        fgets(buffer, MAX_L, stdin);
        sscanf(buffer, "%i", &people[n].age);
    }

    FILE* data;
    if ( (data = fopen("data.bin", "wb")) == NULL )
    {
        printf("Error opening file\n");
        return 1;   
    }

    fwrite(people, sizeof(struct Person) * people_count, 1, data);
    fclose(data);

    return 0;
}