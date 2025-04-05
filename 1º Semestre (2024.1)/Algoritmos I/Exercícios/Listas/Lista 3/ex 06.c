#include <stdio.h>

int main () {

    int cruzamento, xm, ym, xr, yr, i, j;

    scanf("%d %d %d %d", &xm ,&ym ,&xr ,&yr);

    for (i = xm; i < xr; i++) {

        cruzamento++;
    }

    for (j = ym; j < yr; j++) {

        cruzamento++;
    }
    printf("%d", cruzamento);
}