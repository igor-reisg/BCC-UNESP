#include <stdio.h>
#include <string.h>

int main() {
    char frase[100], duplicada[200], palavra[50];
    int pos = 0, i, tam;

    printf("Digite uma frase: ");
    gets(frase); 

    tam = srtlen(frase);

    for (i = 0; tam; i++) {
        if (frase[i] == ' ' || frase[i] == '\n') {
            
            palavra[posicao] = '\0'; 
            strcat(duplicada, palavra); 
            strcat(duplicada, " "); 
            strcat(duplicada, palavra);
            strcat(duplicada, " "); 
            posicao = 0; 
        } 
        else {
            palavra[posicao] = frase[i];
            posicao++;
        }
    }

    printf("Frase duplicada: %s\n", duplicada);

    return 0;
}
