#include <stdio.h>

void unidade(int num) {
    char *unidades[] = {"", "Um", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"};
    printf("%s", unidades[num]);
}

void dezena(int num) {
    char *dezenas[] = {"", "Dez", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa"};
    printf("%s", dezenas[num / 10]);
}

void centena(int num) {
    char *centenas[] = {"", "Cem", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos"};
    printf("%s", centenas[num / 100]);
}

void escreverNumeroExtenso(long long valor) {
    int parte_inteira = valor / 100;
    int centavos = valor % 100;

    centena(parte_inteira / 1000000);

    if (parte_inteira / 100000 != 0) {
        dezena(parte_inteira / 100000);
        unidade((parte_inteira / 1000) % 100);
        printf(" Mil");
    }

    centena((parte_inteira / 100) % 10);

    if (parte_inteira % 100 != 0) {
        if (parte_inteira % 100 < 10) {
            unidade(parte_inteira % 100);
        } 
        else {
            dezena(parte_inteira % 100);
        }
    }

    printf(" Reais");

    dezena(centavos / 10);
    unidade(centavos % 10);
    printf(" Centavos");
}

int main() {
    long long valor;

    printf("Digite um número (até 999.999.999,99): ");
    scanf("%lld", &valor);
    
    escreverNumeroExtenso(valor);
    
    return 0;
}
