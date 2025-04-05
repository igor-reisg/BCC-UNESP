#include<stdio.h>

int main () {

    float n1, n2, n3, n4, med;

    printf("Digite suas 4 notas: ");
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

    med = (n1+n2+n3+n4)/4;

    printf("Media: %.2f\n", med);


    if (med < 5.0) {
        printf("Reprovado\n");
    }
    else if (med >= 5.0 && med < 7.0) {
        printf("Exame\n");
    }
    else
        printf("Aprovado\n");
}
