#include<stdio.h>

int main () {

    int cod;

    printf("Digite o codigo do seu cargo: ");
    scanf("%d", &cod);

    if (cod == 1) {
        printf("Cargo: Escriturario\nPercentual de aumento que tem direito: 60%%\n");
    }
    else if (cod == 2) {
        printf("Cargo: Secretario\nPercentual de aumento que tem direito: 40%%\n");
    }
    else if (cod == 3) {
        printf("Cargo: Caixa\nPercentual de aumento que tem direito: 25%%\n");
    }
    else if (cod == 4) {
        printf("Cargo: Gerente\nPercentual de aumento que tem direito: 5%%\n");
    }
    else if (cod == 5) {
        printf("Cargo: Diretor\nNao tem direito a aumento\n");
    }
    else
        printf("Codigo invalido\n");
}
