#include <stdio.h>

int main () {

    int vetA[10], vetB[20], vetX[30], vetY[30], vetZ[30], i, j;
    int tamA, tamB, continuar = 1, tamX = 0, tamY = 0, tamZ = 0, achou;

    do {
        printf("Digite o tamanho do vetor A (max = 10): ");
        scanf("%d", &tamA);

        for (i = 0; i < tamA; i++) {
            printf("vetA[%d] = ", i);
            scanf("%d", &vetA[i]);
        }

        printf("Digite o tamanho do vetor B (max = 20): ");
        scanf("%d", &tamB);

        for (i = 0; i < tamB; i++) {
            printf("vetA[%d] = ", i);
            scanf("%d", &vetB[i]);
        }

        for (i = 0; i < tamA; i++) {
            vetX[tamX++] = vetA[i];
        }
        for (i = 0; i < tamB; i++) {
            achou = 0;
            for (j = 0; j < tamA; j++) {
                if (vetB[i] == vetA[j]) {
                    achou = 1;
                    break;
                }
            }
            if (!achou) {
                vetX[tamX++] = vetB[i];
            }
        }

        for (i = 0; i < tamA; i++) {
            achou = 0;
            for (j = 0; j < tamB; j++) {
                if (vetA[i] == vetB[j]) {
                    achou = 1;
                    vetY[tamY++] = vetA[i];
                    break;
                }
            }
            if (!achou) {
                vetZ[tamZ++] = vetA[i];
            }
        }

        printf("Vetor X (Uniao):\n");
        for (i = 0; i < tamX; i++) {
            printf("%3d |", vetX[i]);
        }
        printf("\n");

        printf("Vetor Y (Interseccao):\n");
        for (i = 0; i < tamY; i++) {
            printf("%3d |", vetY[i]);
        }
        printf("\n");

        printf("Vetor X (Diferenca):\n");
        for (i = 0; i < tamZ; i++) {
            printf("%3d |", vetZ[i]);
        }
        printf("\n");

        printf("Executar novamente? (1-Sim | 2-Nao) ");
        scanf("%d", &continuar);

        while (continuar != 1 && continuar != 2) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }
    }
    while (continuar == 1);
}