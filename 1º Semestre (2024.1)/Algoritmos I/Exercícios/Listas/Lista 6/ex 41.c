#include <stdio.h>

int main() {
    int i, n, j, m;
    
    printf("Digite os valores de n, j e m: ");
    scanf("%d %d %d", &n, &j, &m);
    
    printf("Os %d primeiros naturais congruentes a %d modulo %d sao:\n", n, j, m);
    
    for (i = 0; i < n; i++) {
        printf("%d ", (j + i) % m);
    }
}
