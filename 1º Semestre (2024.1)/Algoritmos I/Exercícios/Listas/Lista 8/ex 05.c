#include <stdio.h>

int main () {

    int tam, i, soma = 0, continuar = 1, pos = 0, vet[100];

    do {
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tam);

        while (tam <= 0) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &tam);
        }

        for (i = 0; i < tam; i++) {
            printf("Valor posicao %d: ", pos);
            scanf("%d", &vet[i]);

            soma += vet[i];
            pos++;
        }

        printf("Soma: %d\n", soma);

        printf("Executar novamente? (1- Sim | 2- Nao) ");
        scanf("%d", &continuar);

        while (continuar != 1 && continuar != 2) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }

        pos = 0;
        soma = 0;

    } while (continuar == 1);
}