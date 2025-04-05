#include<stdio.h>
#include<math.h>

int main () {

    int a, b, c;
    float delta, raiz1, raiz2, raizun;

    printf("Digite os coeficientes da equacao do 2 grau: ");
    scanf("%d %d %d", &a, &b, &c);

    delta = pow(b, 2)-(4*a*c);

    if(delta > 0){
        raiz1 = (-b+sqrt(delta))/(2*a);

        raiz2 = (-b-sqrt(delta))/(2*a);

        printf("Raiz 1 = %.2f\nRaiz 2 = %.2f", raiz1, raiz2);

    }
    else if (delta == 0) {
        raizun = (-b)/(2*a);

        printf("Raiz 1 e Raiz 2 = %.2f", raizun);

    }
    else 
        printf("NAO EXISTEM RAIZES REAIS");

}