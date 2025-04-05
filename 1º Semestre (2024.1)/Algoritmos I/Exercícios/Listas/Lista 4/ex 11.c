#include<stdio.h>

int main () {
   
    int x, y, z;
   
    printf("Digite 3 comprimentos: ");
    scanf("%d %d %d", &x, &y, &z);
   
    if (z < x+y && x < z+y && y < x+z) {
       
        if (x == y == z) {
            printf("Tringulo equilatero\n");
        }
        else if (x == y || x == z || y == z) {
            printf("Triangulo isosceles\n");
        }
        else
            printf("Triangulo escaleno");
    }
    else
        printf("Os comprimentos nao formam um triangulo\n");
}
