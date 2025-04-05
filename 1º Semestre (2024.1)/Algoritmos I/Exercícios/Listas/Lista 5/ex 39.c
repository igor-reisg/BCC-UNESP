#include <stdio.h>
#include <math.h>

int fat(int n);

int main() {

    double x, soma = 0.0;
    int i, sinal = 1;

    printf("Valor de x: ");
    scanf("%lf", &x);

    for (i = 1; i <= 20; i++) {
        soma += pow(x, i) / (fat(i) * sinal);
        sinal *= -1;
    }

    printf("soma = %.5lf\n", soma);

    return 0;
}

int fat(int n) {

    int fat = 1;
    
    while (n > 1) {
        
        fat *= n;
        n--;
    }
    return fat;
}

