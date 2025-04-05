#include <stdio.h>

int main () {

    int vet[100], i, cont = 1;

    for (i = 0; i < 100; i++) {
        vet[i] = cont;

        printf("%d\n", vet[i]);
        cont++;
    }
}