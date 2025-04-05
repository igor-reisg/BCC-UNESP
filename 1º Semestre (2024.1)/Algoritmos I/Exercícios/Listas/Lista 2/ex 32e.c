#include <stdio.h>

int main() {

    float arearet, base, alt;

    printf("Digite o valor da base e da altura do retangulo: ");
    scanf("%f %f", &base, &alt);

    arearet = base*alt;

    printf("Area do retangulo: %.2f", arearet);
}
