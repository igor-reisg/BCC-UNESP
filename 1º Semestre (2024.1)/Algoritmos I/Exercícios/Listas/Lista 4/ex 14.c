#include<stdio.h>

int main () {

    int cod;

    printf("Digite o codigo do produto: ");
    scanf("%d", &cod);

    if (cod == 1) {
        printf("Alimento nao-perecivel\n");
    }
    else if (cod >= 2 && cod <= 4) {
        printf("Alimento perecivel\n");
    }
    else if (cod == 5 || cod == 6) {
        printf("Vestuario\n");
    }
    else if (cod == 7) {
        printf("Higiene pessoal\n");
    }
    else if (cod >= 8 && cod <= 15) {
        printf("Limpeza e utensilios domesticos\n");
    }
    else
        printf("Invalido\n");
}
