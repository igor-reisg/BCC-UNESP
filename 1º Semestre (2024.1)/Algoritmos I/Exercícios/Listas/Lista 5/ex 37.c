#include <stdio.h>

int main () {

    int i, j, fat, num;
    float s;

    for (i = 100; i >= 89; i--) {
        
        fat = 1;
        for (j = num; j >= 1; j--) {
            
            fat *= j;
        }
        num++;

        s += (float)i/fat;
    }
    
    printf("s = %.2f", s);
}