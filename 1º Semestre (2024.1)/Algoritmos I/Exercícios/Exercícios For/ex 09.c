#include <stdio.h>
#include <math.h>

int main () {

    int i, n, sinal = 1;
    float pi, s;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {

        s += sinal*(float)1/(pow(2*i-1, 3));
        sinal = -sinal;
    }
    pi = pow(32*s, (float)1/3);

    printf("Pi = %f", pi);
}
