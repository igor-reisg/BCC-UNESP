#include <stdio.h>

int main () {

    int n = 1, i, a, b;
    char nome1[10], nome2[10];

    while (n != 0) {

        scanf("%d", &n);
        
        if (n != 0) {
            
            scanf("%s", nome1);
            scanf("%s", nome2);

            for (i = 1; i <= n; i++) {

                scanf("%d %d", &a, &b);

                if ((a+b) % 2 == 0) {
                    printf("%s\n", nome1);
                }
                else
                    printf("%s\n", nome2);

            }
        }
    }
}