#include <stdio.h>

int main () {

    int a1, b1, a2, b2, a, b, area1, area2, areatot, adesejada;

    scanf("%d %d %d %d %d %d", &a1, &b1, &a2, &b2, &a, &b); 

    area1 = a1*b1;

    area2 = a2*b2;

    areatot = area1+area2;

    adesejada = a*b;

    if (area1 < adesejada || area2 < adesejada) {
        if (areatot < adesejada) {
            printf("N\n");
        }
        else
            printf("S\n");
    }
    else if (area1 > adesejada || area2 > adesejada) {
        printf("S\n");
    }
}