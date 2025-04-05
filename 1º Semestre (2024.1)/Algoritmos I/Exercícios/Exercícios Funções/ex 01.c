#include <stdio.h>

int sinal () {

    int x;

    printf("Digite um valor: ");
    scanf("%d", &x);

    if (x < 0) {
        return -1;
    }
    else if (x == 0) {
        return 0;
    }
    else 
        return 1;
}

int main () {

    sinal();
}