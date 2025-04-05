#include <stdio.h>

int main () {

    int i, j; 
    float somaneg = 0, somapos = 0, somatot = 0;

    for (i = 1; i <= 9999; i += 2) {

        somapos += (float)1/i;
    }

    for (j = 2; j <= 10000; j += 2) {

        somaneg += (float)1/j;
    }
    
    somatot = somapos-somaneg;

    printf("s = %.2f\n", somatot);
}