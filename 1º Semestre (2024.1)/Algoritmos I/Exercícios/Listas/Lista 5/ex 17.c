#include <stdio.h>

int main () {

    int i;

    for (i = 3500; i <= 7000; i++) {
        if (i % 2 == 1) {
            printf("%d\n", i);
        }
    }
}