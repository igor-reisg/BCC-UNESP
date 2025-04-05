#include <stdio.h>
#include <math.h>

int main () {

    float a, b, c, p, s;

    printf("Digite o valor do lado a: ");
    scanf("%f", &a);

    printf("Digite o valor do lado b: ");
    scanf("%f", &b);

    printf("Digite o valor do lado c: ");
    scanf("%f", &c);

    p = (a+b+c)/2;

    s = sqrt(p*(p - a)*(p - b)*(p - c));

    printf("A area do triangulo de lados %.2f, %.2f e %.2f eh: %.2f", a, b, c, s);

}