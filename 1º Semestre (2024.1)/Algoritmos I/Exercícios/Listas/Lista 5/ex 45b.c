#include <stdio.h>

int main () {

    int sinal = 1, i; 
    float soma = 0;

    for (i = 1; i <= 10000; i++) {

        soma += (float)sinal*1/i;
        sinal = -sinal;
    }
    
    printf("s = %.2f\n", soma);
}