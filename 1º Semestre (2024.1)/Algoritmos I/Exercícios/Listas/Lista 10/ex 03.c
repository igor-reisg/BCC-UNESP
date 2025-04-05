#include <stdio.h>

int main() {

    int i, areateles, numestrela, fluxoestrela, contestrela = 0;
    int fotonsnecesserario = 40000000, fotonscap;

    scanf("%d", &areateles);

    scanf("%d", &numestrela);

    for (i = 0; i < numestrela; i++) {
        scanf("%d", &fluxoestrela);

        fotonscap = areateles * fluxoestrela;

        if (fotonscap >= fotonsnecesserario) {
            contestrela++;
        }
    }

    printf("%d\n", contestrela);

    return 0;
}
