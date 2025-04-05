#include <stdio.h>

int main() {

    int numquad = 64; 
    int graostot = 0; 
    int graosquad = 1; 
    int i, j;

    for (i = 1; i <= numquad; i++) {
        
        graosquad = 1;

        for (j = 1; j < i; j++) {
            graosquad *= 2;
        }
        graostot += graosquad;
    }

    printf("Graos de trigo que o monge esperava: %d graos\n", graostot);
}
