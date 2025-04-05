#include <stdio.h>

int main() {

    int i, n, primo = 0, continuar = 1;
    
    
    while (continuar == 1) {
        
        printf("Digite um valor: ");
        scanf("%d", &n);
        
        for (i = n - 1; i >= 2; i--) {
            
            if (n % i == 0) {
                primo += 1;
            }
        }
        
        if (primo != 0) {
            printf ("%d nao eh primo\n", n);
        }
        else
            printf("%d eh primo\n", n);
            
        primo = 0;

        printf("Executar novamente? (1-sim | 2-nao)\n");
        scanf("%d", &continuar);
    }
}
