#include <stdio.h>

int main() {
    
    int n, i, x;
    double coeficientes[26], px = 0.0, potencia_x = 1.0;

    printf("Digite o valor de n (n <= 25): ");
    scanf("%d", &n);

    for (i = 0; i <= n; i++) {
        printf("Digite o coeficiente a%d: ", i);
        scanf("%lf", &coeficientes[i]);
    }

    for (x = 1; x <= 10; x++) {
        for (i = 0; i <= n; i++) {
            px += coeficientes[i] * potencia_x;
            potencia_x *= x;
        }
        printf("p(%d) = %.2lf\n", x, px);
    }
}
