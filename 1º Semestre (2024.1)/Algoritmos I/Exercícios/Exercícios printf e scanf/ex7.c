#include <stdio.h>

int main () {

    float quil, comb, med;

    printf("Quantidade de quilometros rodados: ");
    scanf("%f", &quil);

    printf("Quantidade de combustivel gasta em litros: ");
    scanf("%f", &comb);

    med = comb/quil;

    printf("A media de combustivel gasto por km rodado eh %.2f l/km", med);

}