#include <stdio.h>

int main() {
    
    int n, i, a, b, atual, resp = 1;
    
    while (resp == 1) {

        a = 0;
        b = 1;
        
        printf("Digite a quantidade de numeros da serie de Fibonacci: ");
        scanf("%d", &n);
        
        if (n == 1) {
            printf("%d", a);
        }
        else
            printf("%d %d", a, b);
        
        for (i = 2; i < n; i++) {
            atual = a + b;
            
            printf(" %d", atual);
            
            a = b;
            b = atual;
        }
        printf("\n");

        printf("Executar novamente? (1-sim | 2-nao)\n");
        scanf("%d", &resp);
    }
}