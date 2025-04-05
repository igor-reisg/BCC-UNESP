#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char bin[65];
    int dec = 0;
    int tam = strlen(bin), i, base;

    printf("Digite um número binário: ");
    gets(bin);

    for (i = 0; i < tam; i++) {

        if (bin[i] == '0' || bin[i] == '1') {
            base = pow(2, tam - i - 1);

            dec += (bin[i] - '0') * base;
        } 
        else {
            printf("Caractere binário inválido encontrado");
        }
    }

    printf("O número decimal equivalente é: %d\n", dec);
}
