#include <stdio.h>

int main () {

    int i, j;
    float s;

    for (i = 1, j = 38; i <= 37; i++) {

        s += (float)(j * (j-1))/ i;
        j--;
    }
    printf("s = %.2f", s);
}