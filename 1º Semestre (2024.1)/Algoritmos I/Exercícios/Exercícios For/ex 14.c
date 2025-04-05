#include <stdio.h>

int main () {

    int n, m, i, j;
    float x;

    printf("Digite os valores de n e m: ");
    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {

        for (j = 1; j <= m; j++) {
            
            x += i+j;
        }
    }
    printf("x = %f", x);
}