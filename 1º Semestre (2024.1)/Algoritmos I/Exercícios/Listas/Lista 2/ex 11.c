#include<stdio.h>

int main () {

    int DiasAt, DiasNasc, MesAt, MesNasc, AnosAt, AnosNasc;
    float DiasTot;

    printf("Dia, mes e ano atual: ");
    scanf("%d %d %d", &DiasAt, &MesAt, &AnosAt);

    printf("Dia, mes e ano de nascimento: ");
    scanf("%d %d %d", &DiasNasc, &MesNasc, &AnosNasc);

    DiasTot = (AnosAt - AnosNasc)*365.25;
    
    if (MesAt < MesNasc) {
        DiasTot += ((MesNasc - MesAt)*30) - 365;
    }
    else {
        DiasTot += (MesAt - MesNasc)*30;
    }
    
    if (DiasAt < DiasNasc) {
        DiasTot += (DiasNasc - DiasAt) - 30;
    }
    else {
        DiasTot += (DiasAt - DiasNasc);
    }

    printf("%.2f dias vividos", DiasTot);

}
