#include <stdio.h>

int main()
{
    int idade;
   
    printf("Digite a idade do narrador: ");
    scanf("%d", &idade);
   
    if (idade >= 5 && idade <= 7) {
        printf("Categoria infantil A");
    }
    else if (idade >= 8 && idade <= 10) {
        printf("Categoria infantil B");
    }
    else if (idade >= 11 && idade <= 13) {
        printf("Categoria juvenil A");
    }
    else if (idade >= 14 && idade <= 17) {
        printf("Categoria juvenil B");
    }
    else
        printf("Categoria Senior");
}
