#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    char string[50];
    int i, tam = strlen(string);

    printf("Digite uma frase: ");
    gets(string);

    for (i = 0; i < tam; i++) {
            
        string[i] = toupper(string[i]);
    }

    printf("FRASE EM MAIUSCULO:\n%s\n", string);
}