#include <stdio.h>

int main() {
    
    int vet[100], i;
    
    for (i = 0; i < 100; i++) {
        if (i * i == i) {
            vet[i] = 1;
        } else {
            vet[i] = 0;
        }
    }
    
    for (i = 0; i < 100; i++) {
        printf("vet[%d] = %d\n", i, vet[i]);
    }
}
