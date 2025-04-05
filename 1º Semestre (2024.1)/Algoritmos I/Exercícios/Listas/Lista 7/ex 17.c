#include <stdio.h>

int main() {
    
    int p, r;
	
    scanf("%i %i", &p, &r);

    if(p == 0) {
        printf("C");
    } 
    else if (p == 1 && r == 0) {
        printf("B");
    } 
    else if (p == 1 && r == 1) {
        printf("A");
    }
}