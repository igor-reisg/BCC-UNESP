#include<stdio.h>

int main () {

    float preco;
    int cod;

    printf("Digite o preco e o codigo do produto: ");
    scanf("%f %d", &preco, &cod);

    printf("Preco: R$%.2f\n", preco);

    if (cod == 1) {
        printf("Procedencia: Sul\n");
    }
    else if (cod == 2) {
        printf("Procedencia: Norte\n");
    }
    else if (cod == 3) {
        printf("Procedencia: Leste\n");
    }
    else if (cod == 4) {
        printf("Procedencia: Oeste\n");
    }
    else if (cod == 5 || cod == 6 || (cod >= 21 && cod <= 30)) {
        printf("Procedencia: Nordeste\n");
    }
    else if (cod >= 7 && cod <= 9) {
        printf("Procedencia: Sudeste\n");
    }
    else if (cod >= 10 && cod <= 20) {
        printf("Procedencia: Centro-oeste\n");
    }
    else
        printf("Procedencia: Importado\n");
}
