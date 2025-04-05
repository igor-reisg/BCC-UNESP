#include <stdio.h>

int main() {

    int n, i, teste = 1, x, resp;

    scanf("%d", &n);

    while (n != 0) {
        
        resp = -1;
        
        for (i = 1; i <= n; i++) {
            
            scanf("%d", &x);
            
            if (x == i) {
                resp = i;
            }
        }

        printf("Teste %d\n", teste);
        printf("%d\n\n", resp);

        scanf("%d", &n);

        teste++;
    }
}
