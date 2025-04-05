#include <stdio.h>
#include <ctype.h>

int main() {
    
    char frase[1000];
    int i, contcarac = 0, contdig = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    for (i = 0; frase[i] != '\0'; i++) {
        if (isalpha(frase[i])) {
            contcarac++;
        }
        if (isdigit(frase[i])) {
            contdig++;
        }
    }

    printf("Número de caracteres: %d\n", contcarac);
    printf("Número de dígitos: %d\n", contdig);

    return 0;
}
