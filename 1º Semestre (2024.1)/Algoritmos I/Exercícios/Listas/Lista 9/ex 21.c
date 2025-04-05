#include <stdio.h>
#include <string.h>

int main() {

    char nomes[10][50];
    int resp[10], freq[5] = {0}, i;

    for (i = 0; i < 10; i++) {
        printf("Digite o seu nome: ");
        gets(nomes[i]);

        printf("Digite sua resposta (de 1 a 5): ");
        scanf("%d", &resp[i]);

        if (resp[i] < 1 && resp[i] > 5) {
            printf("Resposta invalida. Digite novamente (de 1 a 5): ");
            scanf("%d", &resp[i]);
        }

        switch (resp[i]) {
            case 1:
                freq[0]++;
                break;
            case 2:
                freq[1]++;
                break;
            case 3:
                freq[2]++;
                break;
            case 4:
                freq[3]++;
                break;
            case 5:
                freq[4]++;
                break;
        }
        getchar();
    }

    for (i = 0; i < 10; i++) {
        printf("Nome %d: %s\n", i + 1, nomes[i]);
        printf("Resposta %d: %d\n\n", i + 1, resp[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("%d pessoas responderam %d\n", freq[i], i+1);
    }
}