#include<stdio.h>

int main () {

    int a, b, temp;

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    temp = a;
    a = b;
    b = temp;

    printf("Valor de a: %d\nValor de b: %d", a, b);

}