#include<stdio.h>

int main () {

    int lad, tam;

    printf("Digite o numero de lados do poligono e sua medida: ");
    scanf("%d, %d", &lad, &tam);


    if (lad == 3) {
        printf("TRIANGULO\nPERIMETRO = %d", tam*3);
    }
    else if (lad == 4) {
        printf("QUADRADO\nAREA = %d", tam*2);
    }
    else if (lad == 5) {
        printf("PENTAGONO");
    }
    else
        printf("POLIGONO NAO IDENTIFICADO");
}