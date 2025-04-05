#include <stdio.h>

int main() {

    float areaquad, lado;

    printf("Digite o valor do lado do quadrado: ");
    scanf("%f", &lado);

    areaquad = lado*lado;

    printf("Area do quadrado: %.2f", areaquad);
}
