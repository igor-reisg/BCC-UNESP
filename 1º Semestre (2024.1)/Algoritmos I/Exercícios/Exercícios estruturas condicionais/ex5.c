#include<stdio.h>

int main () {

    float ang1, ang2, ang3;

    printf("Digite os 3 angulos de um triangulo: ");
    scanf("%f %f %f", &ang1, &ang2, &ang3);

    if (ang1 == 90 || ang2 == 90 || ang3 == 90) {
        printf("TRIANGULO RETANGULO\n");
    }
    else if (ang1 > 90 || ang2 > 90 || ang3 > 90) {
        printf("TRIANGULO OBTUSANGULO\n");
    }
    else
        printf("TRIANGULO ACUTANGULO\n");

}