#include <stdio.h>
#include <math.h>

int main () {

    int i;

    printf("NUMERO\tCUBO\n");

    for (i = 15; i <= 30; i++) {
        
        printf("%d\t%.0f\n", i, pow(i, 3));
    }
}
