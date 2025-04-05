#include <stdio.h>

int main () {

    int sinal = -1, i; 
    float soma = 0;

    for (i = 10000; i >= 1; i--) {

        soma += (float)sinal*1/i;
        sinal = -sinal;
    }
    
    printf("s = %.2f\n", soma);
}