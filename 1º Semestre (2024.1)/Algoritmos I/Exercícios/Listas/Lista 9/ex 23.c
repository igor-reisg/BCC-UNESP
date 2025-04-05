#include <stdio.h>
#define MAX_PESSOAS 50 
#define NUM_PERGUNTAS 20

void lerResposta(int respostas[][NUM_PERGUNTAS], int n, char tipo[]) {
    int i, j;

    for (i = 0; i < n; i++) {
        printf("Digite as respostas da %s %d (0 ou 1):\n", tipo, i + 1);
        for (j = 0; j < NUM_PERGUNTAS; j++) {
            scanf("%d", &respostas[i][j]);
        }
    }
}

int calcAfinidade(int respostas1[], int respostas2[]) {
    int afinidade = 0, i;

    for (i = 0; i < NUM_PERGUNTAS; i++) {
        if (respostas1[i] == respostas2[i]) {
            afinidade++;
        }
    }
    return afinidade;
}

void tabelaAfinidade(int afinidade[][MAX_PESSOAS], int n) {
    int i, j;

    printf("\nTabela de Afinidade:\n");
    for (i = 0; i < n; i++) {
        printf("P%d ", i + 1);
        for (j = 0; j < n; j++) {
            printf("%2d ", afinidade[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, respostas[MAX_PESSOAS][NUM_PERGUNTAS], afinidade[MAX_PESSOAS][MAX_PESSOAS], i, j;

    printf("Digite o numero de pessoas (<= 50): ");
    scanf("%d", &n);

    while (n <= 0 && n >= 50) {
        printf("Valor invalido. Digite novamente: ");
        scanf("%d, &n");
    }

    lerResposta(respostas, n, "pessoa");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            afinidade[i][j] = calcAfinidade(respostas[i], respostas[j]);
        }
    }

    tabelaAfinidade(afinidade, n);

    return 0;
}
