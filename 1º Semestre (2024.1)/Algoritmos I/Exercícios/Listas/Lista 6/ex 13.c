#include <stdio.h>

int main () {

    int n, soma = 0, cont = 0, maior, menor, somaimpar = 0, contimpar = 0;
    float med, medimpar, porcpar;

    printf("Digite um valor: ");
    scanf("%d", &n);

    maior = menor = n;
    
    while (n != 100000) {

        if (n != 100000) {

            if (n > maior) {
                maior = n;
            }

            if (n < menor) {
                menor = n;
            }

            soma += n;
            cont++;

            if (n % 2 != 0) {
                somaimpar += n;
                contimpar++;
            }

            printf("Digite um valor: ");
            scanf("%d", &n);
        }
    }

    med = (float)soma/cont;
    medimpar = (float)somaimpar/contimpar;
    porcpar = (float)(cont - contimpar) / cont * 100;

    printf("Soma dos numeros digitados: %d\n", soma);
    printf("Quantidade de numeros digitados: %d\n", cont);
    printf("Media dos numeros digitados: %.2f\n", med);
    printf("Maior numero digitado: %d\n", maior);
    printf("Menor numero digitado: %d\n", menor);
    printf("Media dos numeros impares: %.2f\n", medimpar);
    printf("Porcentagem dos numeros pares digitados: %.2f%%\n", porcpar);
}