#include<stdio.h>

int main () {

    int h1, h2, m1, m2, sum, prod;

    printf("Digite a idade de 2 homens e de 2 mulheres, respectivamente: ");
    scanf("%d %d %d %d", &h1, &h2, &m1, &m2);

    //Homem 1 mais velho
    if (h1 > h2) {
        //Mulher 2 mais nova
        if (m1 > m2) {
            sum = h1+m2;
            prod = h2*m1;
        }
        //Mulher 1 mais nova
        else {
            sum = h1+m1;
            prod = h2*m2;
        }
    }
    //Homem 2 mais velho
    else {
        //Mulher 2 mais nova
        if (m1 > m2) {
            sum = h2+m2;
            prod = h1*m1;
        }
        //Mulher 1 mais nova
        else {
            sum = h2+m1;
            prod = h1*m2;
        }
    }
    
    printf("SOMA DAS IDADE DO HOMEM MAIS VELHO COM A MULHER MAIS NOVA: %d\n", sum);
    printf("PRODUTO DAS IDADE DO HOMEM MAIS NOVO COM A MULHER MAIS VELHA: %d\n", prod);
}