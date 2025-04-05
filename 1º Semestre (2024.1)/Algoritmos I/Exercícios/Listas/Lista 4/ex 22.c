#include <stdio.h>

int main () {

    int graus;

    printf("Digite uma medida de um angulo, em graus: ");
    scanf("%d", &graus);


    if (graus >= -90 && graus <= 90) {
        printf("1 quadrante\n");
    }
    else if ((graus >= 90 && graus <= 180) || (graus <= -90 && graus >= -180)) {
        printf("2 quadrante\n");
    }
    else if ((graus >= 180 && graus <= 270) || (graus <= -180 && graus >= -270)) {
        printf("3 quadrante\n");
    }
    else {
        printf("4 quadrante\n");
    }
}
