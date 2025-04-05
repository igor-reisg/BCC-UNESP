#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 1; 
    int x, y, z;
    int encontrado = 1;

    printf("Digite os valores de x, y e z: ");
    scanf("%d %d %d", &x, &y, &z);

    while (n < 1000 && encontrado == 1) {
        x = n % 3;
        y = n % 5;
        z = n % 7;

        if (x == 2 && y == 3 && z == 4) {
            printf("O menor inteiro positivo que satisfaz as condicoes eh: %d\n", n);
            
            encontrado = 0; 
        }
        n++;
    }
}
