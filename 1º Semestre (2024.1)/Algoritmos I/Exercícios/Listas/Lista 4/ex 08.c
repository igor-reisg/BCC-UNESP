#include<stdio.h>

int main () {
   
    int a, b, c;
   
    printf("Digite 3 valores inteiros: ");
    scanf("%d %d %d", &a, &b, &c);
   
    if (a <= b && b <= c || a <= c && c <= b) {
        printf("O menor valor eh: %d", a);
    }
    else if (b <= a && a <= c || b <= c && c <= a) {
        printf("O menor valor eh: %d", b);
    }
    else
        printf("O menor valor eh %d", c);
}
