#include <stdio.h>

int main() {
    
    int i, n, caso, soma = 0, continuar = 1;
    
    while (continuar == 1) {
    
        printf("Digite um valor: ");
        scanf("%d", &n);
        
        for (i = 1; i < n; i++) {
            
            if (n % i == 0) {
                soma += i;
            }
        }
        
        if (n == soma) {
            printf("%d eh perfeito\n", n);
        }
        else
            printf("%d nao eh perfeito\n", n);
            
        soma = 0;

        printf("Executar novamente? (1-sim | 2-nao)\n");
        scanf("%d", &continuar);
    }
}