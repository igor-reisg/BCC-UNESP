#include <stdio.h>
#include <string.h>

void bubbleSort(char vetor[][50], int tam) {
    int i, j;
    char temp[50];
    
    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - i - 1; j++) {
            
            if (strcmp(vetor[j], vetor[j + 1]) < 0) {
                
                strcpy(temp, vetor[j]);
                strcpy(vetor[j], vetor[j + 1]);
                strcpy(vetor[j + 1], temp);
            }
        }
    }
}

int main() {
    char vetor[20][50];
    int tam, i;

    printf("Digite o tamanho do vetor (ate 20): ");
    scanf("%d", &tam);

    printf("Digite as strings do vetor:\n");
    for (i = 0; i < tam; i++) {
        scanf("%s", vetor[i]);
    }

    bubbleSort(vetor, tam);

    printf("Vetor ordenado em ordem decrescente:\n");
    for (i = 0; i < tam; i++) {
        printf("%s\n", vetor[i]);
    }
    return 0;
}
