#include <stdio.h>

int main() {
    char frase[100]; 
    int caracteres = 0, palavras = 0, i;

    printf("Digite uma frase: ");
    gets(frase); 

    for (i = 0; frase[i] != '\0'; i++) {
        caracteres++; 

        if (frase[i] == ' ') {
        palavras++; 
        }
    }

    printf("Existem %d caracteres e %d palavras nesta frase.\n", caracteres, palavras + 1); // + 1 para contar a última palavra

    return 0;
}
