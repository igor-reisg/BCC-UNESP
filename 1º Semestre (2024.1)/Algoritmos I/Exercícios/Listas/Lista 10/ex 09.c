#include <stdio.h>

int main() {
    int numeroQuestoes, acertos = 0, i;
    char gabarito[81], respostas[81];

    scanf("%d %s %s", &numeroQuestoes, gabarito, respostas);

    for (i = 0; i < numeroQuestoes; i++) {
        
        if (gabarito[i] == respostas[i]) {
            acertos++;
        }
    }
    printf("%d\n", acertos);

    return 0;
}
