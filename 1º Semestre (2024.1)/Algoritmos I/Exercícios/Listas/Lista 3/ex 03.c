#include<stdio.h>

int main () {

    int N;

    printf("Informe a nota do aluno: ");
    scanf("%d", &N);

    if (N == 0) {
        printf("E");
    }
        else if (N >= 1 && N<=35) {
            printf("D");
        }
            else if (N >= 36 && N <=60) {
                printf("C");
            }
                else if (N >=61 && N <=85) {
                    printf("B");
                }
                    else {
                        printf("A");
                    }

}