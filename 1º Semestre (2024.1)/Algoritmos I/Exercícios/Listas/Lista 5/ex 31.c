#include <stdio.h>
#include <math.h>

int main () {

    int i, sinal = 1;
    float s;

    for (i = 1; i <= 10; i++) {
        
        s += sinal*(float)(pow(i, 2))/(i);
        sinal = -sinal;
    }

    printf("s = %.2f", s);
}