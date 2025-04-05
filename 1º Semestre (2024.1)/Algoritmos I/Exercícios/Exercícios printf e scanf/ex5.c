#include<stdio.h>

int main () {

    int hr, min, seg, total;

    printf("Digite uma quantidade em horas, minutos e segundos, respectivamente: ");
    scanf("%d %d %d", &hr, &min, &seg);

    total = hr*3600 + min*60 + seg;

    printf("A quantidade total em segundos eh: %d", total);

}