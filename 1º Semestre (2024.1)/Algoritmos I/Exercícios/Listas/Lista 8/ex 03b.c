#include <stdio.h>

int main () {

    int vet[100], i;

    vet[0] = 10;

    for (i = 1; i < 100; i++) {
        vet[i] = 10 + vet[i-1];
    }

    for (i = 0; i < 100; i ++) {
        printf("%d\n", vet[i]);
    }
} 