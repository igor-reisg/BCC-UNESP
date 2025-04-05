#include <stdio.h>

int main () {

    int num, i, j;
    float soma = 0, somapos = 0, somaneg = 0;

    for (i = 500; i >= 50; i -= 100) {
 
        num = 2;

        somapos += (float)num/i;
    }

    for (j = 450; j >= 50; j -= 100) {

        num = 5;

        somaneg += (float)num/j;
    }

    soma = somapos-somaneg;

    printf("soma = %.2f\n", soma);
}