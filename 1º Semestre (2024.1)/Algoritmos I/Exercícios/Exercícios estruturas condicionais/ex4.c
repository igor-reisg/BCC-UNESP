#include<stdio.h>

int main () {

    int l1, l2, l3;

    printf("Digite o valor dos lados do triangulo: ");
    scanf("%d %d %d", &l1, &l2, &l3);

    if (l1 == l2 && l2 == l3) {
        printf("TRIANGULO EQUILATERO");
    }
    else if (l1 == l2 || l2 == l3 || l3 == l1) {
        printf("TRIANGULO ISOSCELES");
    }
    else
        printf("TRIANGULO ESCALENO");
}