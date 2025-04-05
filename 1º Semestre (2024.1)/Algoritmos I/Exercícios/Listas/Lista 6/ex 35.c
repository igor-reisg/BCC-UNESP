#include <stdio.h>

int main() {
    int num, div = 2;
    
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);
    
    printf("Fatores primos de %d:\n", num);
    
    while (num > 1) {

        if (num % div == 0) {

            printf("%d\n", div);
            num /= div;
        }
        else 
            div++;
    }
    printf("\n");
}
