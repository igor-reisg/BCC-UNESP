#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main() {
    int n, m, seguidores[30], soma = 0, count = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < 30; i++) {
        scanf("%d", &seguidores[i]);
        soma += seguidores[i];
    }

    int index = 0;

    while (n < m) {
        count++;
        int media = (int)ceil(soma / 30.0);
        n += media;

        soma -= seguidores[index];
        seguidores[index] = media;
        soma += media;

        index = (index + 1) % 30;
    }

    printf("%d\n", count);
}
