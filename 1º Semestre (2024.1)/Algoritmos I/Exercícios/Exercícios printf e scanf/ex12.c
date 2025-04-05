#include <stdio.h>
#include <math.h>

int main () {

    float r, vol;

    printf("CALCULO VOLUME DE UMA ESFERA\nDigite o valor do raio: ");
    scanf("%f", &r);

    vol = M_PI*pow(r, 3)*4/3;

    printf("O volume da esfera eh %.2f", vol);

}