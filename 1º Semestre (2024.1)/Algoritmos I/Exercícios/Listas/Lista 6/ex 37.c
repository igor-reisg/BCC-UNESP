#include <stdio.h>

int main() {
    int i, dez1, dez2;

    for (i = 1000; i < 10000; i++) {

        dez1 = i / 100;
        dez2 = i % 100;
        
        if ((dez1 + dez2) * (dez1 + dez2) == i) {
            printf("%d\n", i);
        }
    }
}
