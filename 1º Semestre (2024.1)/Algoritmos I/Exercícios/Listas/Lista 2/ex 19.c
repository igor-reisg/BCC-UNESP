#include <stdio.h>

int main () {
	
    int x, y;

    printf("Digite 2 numeros inteiros: ");
    scanf("%d %d", &x, &y);

    printf("%d + %d = %d\n", x, y, x+y);
    printf("%d - %d = %d\n", x, y, x-y);
    printf("%d - %d = %d\n", y, x, y-x);
    printf("%d * %d = %d\n", x, y, x*y);
    printf("%d / %d = %.2f\n", x, y, (float)x/y);
    printf("%d / %d = %.2f\n", y, x, (float)y/x);
    printf("%d / %d = %d\n", x, y, x/y);
    printf("%d / %d = %d\n", y, x, y/x);
    printf("%d %% %d = %d\n", x, y, x%y);
    printf("%d %% %d = %d\n", y, x, y%x);

}

