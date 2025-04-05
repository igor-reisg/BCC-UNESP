#include <stdio.h>
#include <math.h>

int main() {

    float areacirc, raio;

    printf("Digite o valor do raio do circulo: ");
    scanf("%f", &raio);

    areacirc = M_PI*raio*raio;

    printf("Area do circulo: %.2f", areacirc);
}
