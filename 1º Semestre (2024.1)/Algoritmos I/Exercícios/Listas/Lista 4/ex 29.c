#include <stdio.h>

int main () {

    int hrextra, hrfalta, premio;
    float H;

    printf("Digite o numero de horas extras e de horas-falta (min): ");
    scanf("%d %d", &hrextra, &hrfalta);

    H = (hrextra)-((float)2/3*hrfalta);

    if (H > 2400) {
        premio = 800;
    }
    else if (H > 1800 && H <= 2400) {
        premio = 600;
    }
    else if (H > 1200 && H <= 1800) {
        premio = 550;
    }
    else if (H > 600 && H <= 1200) {
        premio = 400;
    }
    else
        premio = 350;

    printf("Horas extras: %.2f horas\n", (float)hrextra/60);
    printf("Horas-faltas: %.2f horas\n", (float)hrfalta/60);
    printf("Premio: R$%d\n", premio);
}
