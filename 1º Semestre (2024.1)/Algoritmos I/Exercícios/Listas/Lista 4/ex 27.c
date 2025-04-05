#include<stdio.h>
#include<math.h>

int main () {

    int cod;
    float num1, num2;

    printf("Escolha 1 opcao:\n1 - Soma\n2 - Produto\n3 - Raiz quadrada\n4 - Sair\n");
    scanf("%d", &cod);

    if (cod >= 1 && cod <= 3) {

        printf("\nDigite os 2 numeros: ");
        scanf("%f %f", &num1, &num2);

        if (cod == 1) {
            printf("\n%.2f + %.2f = %.2f\n", num1, num2, num1+num2);
        }
        else if (cod == 2) {
            printf("\n%.2f * %.2f = %.2f\n", num1, num2, num1*num2);
        }
        else if (cod == 3) {
            printf("\nRaiz quadrada de %.2f", num1, num2, num1*num2);
        }
    }
}
