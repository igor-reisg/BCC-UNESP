#include <stdio.h>
#include <string.h>
#include <math.h>

int binDec(char *binario) {
    
    int decimal = 0, comprimento = strlen(binario), i;

    for (i = 0; i < comprimento; i++) {
        
        if (binario[comprimento - i - 1] == '1') {
            decimal += pow(2, i);
        }
    }

    return decimal;
}

int main() {
    char binario[65], decimal;

    printf("Digite um numero binario: ");
    scanf("%s", binario);

    decimal = binDec(binario);

    printf("O numero decimal equivalente eh: %d\n", decimal);

    return 0;
}
