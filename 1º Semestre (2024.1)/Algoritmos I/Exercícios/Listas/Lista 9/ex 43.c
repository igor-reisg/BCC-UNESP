#include <stdio.h>

int main() {
    
    int n, k, i, j, custoTot, custos[20][20], cidades[20]; 

    printf("Digite a qtd de itinerarios e qtd de cada cidade: ");
    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
        scanf("%d", &custos[i][j]);
        }
    }

    custoTot = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
        scanf("%d", &cidades[j]);
        }

        for (j = 0; j < k - 1; j++) {
        custoTot += custos[cidades[j] - 1][cidades[j + 1] - 1];
        }

        printf("O custo do itinerario %d eh %d\n", i + 1, custoTot);
    }

    return 0;
}
