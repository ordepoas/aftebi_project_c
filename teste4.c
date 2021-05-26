#include <stdio.h>
#include <string.h>

int checkCaracter(char *a, char *b) {
    //if a contém b
    if (strstr(a, b)) {

    return 1;
    }

    return 0;

}

int main() {

    char a[20], b[20];
    strcpy(a, "teste@Teste");
    strcpy(b, "este");

    int res;

    res = checkCaracter(a, b);
    printf("%d\n", res);

    return 0;
}