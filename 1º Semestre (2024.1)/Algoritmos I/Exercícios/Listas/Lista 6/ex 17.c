#include <stdio.h>

int main () {

    float altfulano = 1.50, crescfulano = 0.02, altciclano = 1.1, crescciclano = 0.03;
    int cont = 0;

    while (altfulano > altciclano) {
           
            altfulano += crescfulano;
            
            altciclano += crescciclano;
            
            cont++;
        }

        printf("%d anos.\n", cont);
}