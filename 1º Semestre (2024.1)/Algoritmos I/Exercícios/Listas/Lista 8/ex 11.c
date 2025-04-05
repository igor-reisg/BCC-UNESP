#include <stdio.h>

int main () {

    int vet[50], chave, i, tam, count = 0;

    printf("Digite o tamanho do vetor (Maximo de 50): ");
    scanf("%d", &tam);

    for (i = 0; i < tam; i++) {
        printf("vet[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    printf("Digite o valor de K: ");
    scanf("%d", &chave);

    for (i = 0; i < tam; i++) {
        if (vet[i] == chave) {
            break;
        }
        count++;
    }

    if (vet[i] == chave) {
        printf("A chave foi encontrada na posicao %d\n", count);
    }
    else
        printf("A chave nao foi encontrada dentro do vetor\n");
}