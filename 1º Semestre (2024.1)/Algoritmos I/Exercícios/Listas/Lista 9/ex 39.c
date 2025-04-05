#include <stdio.h>

int compararDatas(int *data1, int *data2) {
    if (data1[2] > data2[2]) {
        return 1;
    } 
    else if (data1[2] < data2[2]) {
        return -1;
    } 
    else {
        if (data1[1] > data2[1]) {
            return 1;
        } 
        else if (data1[1] < data2[1]) {
            return -1;
        } 
        else {
            if (data1[0] > data2[0]) {
                return 1;
            }
            else if (data1[0] < data2[0]) {
                return -1;
            } 
            else {
                return 0;
            }
        }
    }
}

void sort(int datas[][3], int n) {
    
    int i, j, tempDia, tempMes, tempAno;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (compararDatas(datas[j], datas[j + 1]) > 0) {

                tempDia = datas[j][0];
                datas[j][0] = datas[j + 1][0];
                datas[j + 1][0] = tempDia;

                tempMes = datas[j][1];
                datas[j][1] = datas[j + 1][1];
                datas[j + 1][1] = tempMes;

                tempAno = datas[j][2];
                datas[j][2] = datas[j + 1][2];
                datas[j + 1][2] = tempAno;
            }
        }
    }
}

int main() {
    int n, i, datas[100][3];

    printf("Digite a quantidade de datas: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &datas[i][0], &datas[i][1], &datas[i][2]);
    }
    printf("\n");

    sort(datas, n);

    printf("Datas ordenadas:\n");
    for (i = 0; i < n; i++) {
        printf("%d %d %d\n", datas[i][0], datas[i][1], datas[i][2]);
    }

    return 0;
}
