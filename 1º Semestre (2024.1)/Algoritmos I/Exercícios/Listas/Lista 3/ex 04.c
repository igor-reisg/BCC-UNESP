#include<stdio.h>

int main () {

    int i, anoat;

    printf("Digite o ano atual: ");
    scanf("%d", &anoat);

    for (i = 1986; i <= 10076; i += 76) {
        
        if (anoat < i) {
            printf("%d", i);
            break;
        }
    }
}