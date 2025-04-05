#include <stdio.h>

int somadiv(int a, int b, int c) {

    int i, soma = 0;

    for (i = b; i <= c; i++) {

         if (i % a == 0) {
            soma += i;
        }   
    }
    return soma;
}

int main () {

    int a, b, c;

    printf("Digite o valor de a, b e c (a > 0): ");
    scanf("%d %d %d", &a, &b, &c);

    printf("A soma dos numeros inteiros divisiveis por %d entre %d e %d eh: %d", a, b, c, somadiv(a, b, c));
}