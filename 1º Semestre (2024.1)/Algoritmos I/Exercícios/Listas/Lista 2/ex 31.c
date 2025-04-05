#include<stdio.h>

int main () {
   
    int hr, min, totmin;
    
    printf("Dgite uma hora (hora.min): ");
    scanf("%d.%d", &hr, &min);
    
    totmin = hr*60+min;
    
    printf("O horário %d.%d em minutos é %d min", hr, min, totmin);
   
}
