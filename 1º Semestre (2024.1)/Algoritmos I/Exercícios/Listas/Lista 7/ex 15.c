#include <stdio.h>

int main() {
    
    int a, b, c;
    int h, l;
    int cabe;

    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d", &h, &l);

    cabe = (a <= h && b <= l) || (b <= h && c <= l) || (c <= h && a <= l) ||
    (b <= h && a <= l) || (c <= h && b <= l) || (a <= h && c <= l);

    if (cabe == 1) {
        printf("S\n");
    }
    else
        printf("N\n");
}