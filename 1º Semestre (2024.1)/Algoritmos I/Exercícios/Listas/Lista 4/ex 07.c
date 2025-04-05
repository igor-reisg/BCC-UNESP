#include <stdio.h>

int main() {

    int peso, novopeso;
   
    printf("Digite o seu peso, em kg: ");
    scanf("%d", &peso);
   
    novopeso = (peso*1000*5/100) + peso*1000;
   
    printf("Peso em gramas: %d g\n", peso*1000);
    printf("Peso ao engordar 5%%: %d g\n", novopeso);
}
