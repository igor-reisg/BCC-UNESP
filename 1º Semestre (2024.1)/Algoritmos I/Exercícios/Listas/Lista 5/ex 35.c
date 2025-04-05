#include <stdio.h>
#include <math.h>

int main() {

    int i, sinal = 1;
    float s = 0, pi;

    for (i = 1; i <= 30; i++) {
        
        s += sinal*(float)1/pow(2*i-1, 3);
        sinal = -sinal;
    }

    pi = pow(32*s, (float)1/3);
    
    printf("Valor de pi: %f", pi);
}
