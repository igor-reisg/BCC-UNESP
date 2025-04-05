#include<stdio.h>

int main () {

    float a, b, c, d, u, v, x, y;

    printf("Digite o valor dos parametros a, b, c, d, u e v do sistema: ");
    scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &u, &v);

    if (a*d - b*c != 0) {

        x = d/(a*d-b*c)*u-(b/a*d-b*c)*v;

        y = (-c)/(a*d-b*c)*u+(a/a*d-b*c)*v;

    }
    else
        printf("Impossivel calcular\n");

    printf("x = %.2f\ny = %.2f\n", x, y);
}
