#include <stdio.h>

int main() {

    float areatrap, a, b, alt;

    printf("Digite o valor das bases e da altura do trapezio: ");
    scanf("%f %f %f", &a, &b, &alt);

    areatrap = (a+b)/2*alt;

    printf("Area do trapezio: %.2f", areatrap);
}
