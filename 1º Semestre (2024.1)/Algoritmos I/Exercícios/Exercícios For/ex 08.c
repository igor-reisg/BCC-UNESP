#include <stdio.h>

int main () {

    int i;
    float s;

    for (i = 1; i <= 50; i++) {
        
        s += (float)(i*2-1)/i;
    }
    printf("S = %.2f", s);
}