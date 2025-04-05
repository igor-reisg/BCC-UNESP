#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define lin 10

int main() {

    int i, j, vet[lin], temp, achou;
    
    srand(time(NULL));

    for (i = 0; i < lin; i++) {
        do {
            vet[i] = rand() % 30 + 1;
            achou = 0;
            for (j = 0; j < i; j++) {
                if (vet[i] == vet[j]) {
                    achou = 1;
                }
            }
        }
        while (achou);
    }
    
    printf("VETOR GERADO:\n");
    for (i = 0; i < lin; i++) {
        printf("%3d |", vet[i]);
    }

    //Bubble Sort
    for (i = lin - 1; i > 1; i--) {
        for(j = 0; j < i; j++) {
            if (vet[j] > vet[j + 1]) {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
    
    printf("\nVETOR ORDENADO:\n");
    for (i = 0; i < lin; i++) {
        printf("%3d |", vet[i]);
    }
    
    return 0;
}
