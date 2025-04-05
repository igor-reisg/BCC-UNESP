#include<stdio.h>

int main () {

    float prova1, prova2, optativa, med;

    printf("Digite a nota da prova 1, prova 2 e optativa, respectivamente: ");
    scanf("%f %f %f", &prova1, &prova2, &optativa);

    if (optativa >= 0) {

        if (prova2 > prova1) {
            med = (prova2+optativa) / 2;
        }
        else
            med = (prova1+optativa) / 2;
    }
    printf("MEDIA = %.2f\n", med);

    if (med >= 5) {
        printf("ALUNO APROVADO");
    }
    else if (med >= 3) {
        printf("ALUNO EM EXAME");
    }
    else
        printf("ALUNO REPROVADO");

}