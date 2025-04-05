#include <stdio.h>

int soma(int x, int y) {

    int i, soma = 0;

    for (i = x + 1; i < y; i++) {
        
        soma += i;
    }
    return soma;
}

int main () {

    int a, b;
    
    printf("Digite 2 valores:");
    scanf("%d %d", &a, &b);

    printf("A soma entre os valores de %d e %d eh: %d", a, b, soma(a, b));
}