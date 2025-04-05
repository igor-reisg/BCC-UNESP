#include<stdio.h>

int main () {

    int i;
    float salin = 1250.0, sal2001, sal2002;

    sal2001 = salin*1.025;

    sal2002 = sal2001*1.05;

    for (i = 1; i <= 22; i++) {
        sal2002 *= 1.05;
    }

    printf("Salario atual: R$%.2f", sal2002);
}
