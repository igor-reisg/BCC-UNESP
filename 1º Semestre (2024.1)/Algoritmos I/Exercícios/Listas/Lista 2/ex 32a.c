#include <stdio.h>

int main() {

    float areatr, base, alt;

    printf("Digite o valor da base e da altura do triangulo: ");
    scanf("%f %f", &base, &alt);

    areatr = base*alt/2;

    printf("Area do triangulo: %.2f", areatr);
}
