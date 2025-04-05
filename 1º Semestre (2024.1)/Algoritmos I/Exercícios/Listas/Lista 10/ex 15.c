#include <stdio.h>

int main () {

    int vet[100], maior, i;

    scanf("%d", &vet[0]);

    maior = vet[0];

    for (i = 1; i < 100; i++) {
        scanf("%d", &vet[i]);

        if (vet[i] == 0) {
            break;
        }
        else {
            if (vet[i] > maior) {
                maior = vet[i];
            }
        }
    }
    printf("%d", maior);

    return 0;
}