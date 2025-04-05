#include<stdio.h>

int main () {

    float ntlab, ntprova, ntexame, med;
    char conc;

    printf("Digite sua nota do trabalho de laboratorio, avaliacao semestral e de exame final: ");
    scanf("%f %f %f", &ntlab, &ntprova, &ntexame);

    med = (ntlab*3+ntprova*2+ntexame*5)/10;

    if (med >= 8.5 && med <= 10.0) {
        conc = 'A';
    }
    else if (med >= 7.0 && med < 8.5) {
        conc = 'B';
    }
    else if (med >= 6.0 && med < 7.0) {
        conc = 'C';
    }
    else if (med >= 5.0 && med < 6.0) {
        conc = 'D';
    }
    else
        conc = 'E';

    printf("Media: %.2f\nConceito: %c", med, conc);
}
