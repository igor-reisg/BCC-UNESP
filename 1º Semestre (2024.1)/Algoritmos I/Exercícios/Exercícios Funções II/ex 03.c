#include <stdio.h>

void sort(int vet[], int tam);
void junta(int vetA[], int vetB[], int vetC[], int tamA, int tamB);

int main() {
    int vetA[50], vetB[50], vetC[100], i, tamA, tamB, tamC;

    printf("Digite o tamanho do vetor A e B: ");
    scanf("%d %d", &tamA, &tamB);

    printf("Digite os valores do vetA: ");
    for (i = 0; i < tamA; i++) {
        scanf("%d", &vetA[i]);
    }

    printf("Digite os valores do vetB: ");
    for (i = 0; i < tamB; i++) {
        scanf("%d", &vetB[i]);
    }

    tamC = tamA + tamB;

    sort(vetA, tamA);
    sort(vetB, tamB);

    junta(vetA, vetB, vetC, tamA, tamB);

    printf("VETOR C:\n");
    for (i = 0; i < tamC; i++) {
        printf("%d ", vetC[i]);
    }
}

void sort(int vet[], int tam) {
    int i, j, aux;

    for (i = 0; i < tam - 1; i++) {
        for (j = i + 1; j < tam; j++) {
            if (vet[i] > vet[j]) {
                aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }
    }
}

void junta(int vetA[], int vetB[], int vetC[], int tamA, int tamB) {

    int i = 0, j = 0, k = 0;

    while (i < tamA && j < tamB) {

        if (vetA[i] <= vetB[i]) {
            vetC[k++] = vetA[i++];
        }
        else
            vetC[k++] = vetB[j++];
    }

    while (i < tamA) {
        vetC[k++] = vetA[i++];
    }

    while (j < tamB) {
        vetC[k++] = vetB[j++];
    }
}
