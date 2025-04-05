#include <stdio.h>

int main () {

    float i, inicio, fim, cel;

    printf("Digite os valores incial e final da tabela de conversao: ");
    scanf("%f %f", &inicio, &fim);

    printf("FAHRENHEIT\tCELSIUS\n");

    for (i = inicio; i <= fim; i += 0.5) {

        cel = (i - 32)/1.8;

        printf("%.2f\t\t%.2f\n", i, cel);
    }
}
