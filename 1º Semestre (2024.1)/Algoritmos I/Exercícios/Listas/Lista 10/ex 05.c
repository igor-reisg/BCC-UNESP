#include <stdio.h>
#define MAX_S 1000

void bubble_sort(int intervalos[MAX_S][2], int S) {
    int i, j, temp1, temp2;

    for (i = 0; i < S - 1; i++) {
        for (j = 0; j < S - i - 1; j++) {
            if (intervalos[j][0] > intervalos[j + 1][0]) {

                temp1 = intervalos[j][0];
                temp2 = intervalos[j][1];
                intervalos[j][0] = intervalos[j + 1][0];
                intervalos[j][1] = intervalos[j + 1][1];
                intervalos[j + 1][0] = temp1;
                intervalos[j + 1][1] = temp2;
            }
        }
    }
}

int main() {
    int N, S, i, tamRes;
    int intervalos[MAX_S][2];
    int resultado[MAX_S][2];
    
    scanf("%d %d", &N, &S);

    for (i = 0; i < S; i++) {
        scanf("%d %d", &intervalos[i][0], &intervalos[i][1]);
    }

    bubble_sort(intervalos, S);

    resultado[0][0] = intervalos[0][0];
    resultado[0][1] = intervalos[0][1];
    tamRes = 1;

    for (i = 1; i < S; i++) {
        
        if (intervalos[i][0] <= resultado[tamRes - 1][1]) {
            if (intervalos[i][1] > resultado[tamRes - 1][1]) {
                resultado[tamRes - 1][1] = intervalos[i][1];
            }
        } 
        else {
            resultado[tamRes][0] = intervalos[i][0];
            resultado[tamRes][1] = intervalos[i][1];
            tamRes++;
        }
    }

    for (i = 0; i < tamRes; i++) {
        printf("%d %d\n", resultado[i][0], resultado[i][1]);
    }

    return 0;
}
