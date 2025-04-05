#include <stdio.h>
#include <string.h>

int main() {
    
    char frase[50], temp;
    int tam, i;
    
    printf("Digite uma frase: ");
    gets(frase);
    
    tam = strlen(frase);

    for (i = 0; i < tamanho / 2; i++) {
        temp = frase[i];
        frase[i] = frase[tamanho - i - 1];
        frase[tamanho - i - 1] = temp;
    }

    printf("Frase invertida: %s\n", frase);
    return 0;
}
