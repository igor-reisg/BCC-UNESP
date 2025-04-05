#include <stdio.h>


void div(int x, int y, int *quoc, int *resto) {
    *quoc = 0;  
    *resto = x;
   
    while (*resto >= y) {
        *resto -= y;    
        (*quoc)++;      
    }
}

int main() {
    int quoc = 0, resto, x, y;

    printf("Digite o dividendo: ");
    scanf("%d", &x);

    printf("Digite o divisor: ");
    scanf("%d", &y);

    div(x, y, &quoc, &resto);

    printf("Quociente da divisao: %d\nResto da divisao: %d\n", quoc, resto);

    return 0;
}
