#include<stdio.h>
#include<math.h>

int main () {

    float r1, r2, run, delta, a, b, c;

    printf("Digite os valores de a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    delta = pow(b, 2)-(float)4*a*c;

    if (delta < 0 || a == 0) {
       printf("Nao existem raizes reais\n");
    }
    else if (delta > 0) {
        r1 = (-b+sqrt(delta))/(2*a);

        r2 = (-b-sqrt(delta))/(2*a);

        printf("r1 = %.2f\nr2 = %.2f\n", r1, r2);
    }
    else {
        run = (-b)/(2*a);

        printf("r1 = %.2f\nr2 = %.2f\n", run, run);
    }
}
