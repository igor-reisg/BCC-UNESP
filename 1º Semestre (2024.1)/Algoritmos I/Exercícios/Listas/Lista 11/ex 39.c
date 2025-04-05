#include <stdio.h>

int inverterNumero(int numero) {
  
    int invertido = 0;
    
    while (numero > 0) {
        invertido = invertido * 10 + numero % 10;
        numero /= 10;
    }
    return invertido;
}

int main() {
    int i;

    for (i = 1; i <= 9999; i++) {
       
        if (i == inverterNumero(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}
