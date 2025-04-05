#include <stdio.h>
#include <string.h>

void substituirEspacos(char *str) {
    int i, j, tam = srlen(str), novotam = 0;

    for (i = 0; i < tam; i++) {
        
        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' ')) {
            str[novotam++] = str[i];
        }
    }

    str[novotam] = '\0';
}

int main() {
    
    char string[100];

    printf("Digite uma frase: ");
    gets(string);
    
    substituirEspacos(string);
    
    printf("String apos substituicao de espacos: %s\n", string);
   
    return 0;
}
