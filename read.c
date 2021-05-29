#include <stdlib.h>
#include <stdio.h>

struct Person 
{
    char f_name[256];
    char l_name[256];
    int age;
};

int main()
{
    FILE* data;
    if ((data = fopen("data.bin", "rb")) == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    struct Person people[2];

    for (int i = 0; i < 2; i++) {
    fread(people, sizeof(struct Person) * 2/* Just read one person */, 1, data);
    printf("%s %s\n", people[i].f_name, people[i].l_name);
    }
    fclose(data);

    return 0;
}