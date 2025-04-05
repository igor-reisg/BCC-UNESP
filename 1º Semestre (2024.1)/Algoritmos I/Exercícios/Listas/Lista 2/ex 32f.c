#include <stdio.h>

int main() {

    float arealos, diagmenor, diagmaior;

    printf("Digite o valor da diagonal maior e da menor do losango: ");
    scanf("%f %f", &diagmaior, &diagmenor);

    arealos = diagmaior*diagmenor/2;

    printf("Area do losango: %.2f", arealos);
}
