#include <stdio.h>

int main() {

    int x, y, quoc = 0, resp = 1;
    
    while (resp == 1) {
        printf("Digite 2 valores: ");
        scanf("%d %d", &x, &y);
        
        while (y <= x) {
            x -= y;
            quoc++;
        }
        printf("Resto: %d\nQuociente: %d\n", x, quoc);
        
        printf("Executar novamente? (1-sim | 2-nao)\n");
        scanf("%d", &resp);
    }
}
