#include <stdio.h>

int main() {

    int a, b, i, l, p, c;
    a = b = 1;
    scanf ("%d %d",&l,&p);
    i = 1;
    
    while (i <= l) {
        c = a + b;
        printf ("\n%d",c);
        a = b;
        b = c;
        i += p;
    }
}