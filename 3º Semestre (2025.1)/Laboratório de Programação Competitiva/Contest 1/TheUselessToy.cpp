#include <bits/stdc++.h>
using namespace std;

int main() {
    string direcoes;
    long long duracao;
    int flag = 0, j, k;

    getline(cin, direcoes);
    cin >> duracao;

    int inicio = 0;
    if (direcoes[0] == '^') inicio = 0;
    else if (direcoes[0] == '>') inicio = 1;
    else if (direcoes[0] == 'v') inicio = 2;
    else if (direcoes[0] == '<') inicio = 3;

    int fim = 0;
    if (direcoes[2] == '^') fim = 0;
    else if (direcoes[2] == '>') fim = 1;
    else if (direcoes[2] == 'v') fim = 2;
    else if (direcoes[2] == '<') fim = 3;

    if (inicio == fim) {
        cout << "undefined" << endl;
        return 0;
    }

    if ((inicio + 2) % 4 == fim || (inicio - 2 + 4) % 4 == fim) {
        cout << "undefined" << endl;
        return 0;
    }

    j = inicio;
    k = inicio;

    for (int i = 0; i < duracao; i++) {
        j++;
        k--;
        
        if (j > 3) {
            j = 0;
        }
        if (k < 0) {
            k = 3;
        }
    }

    if (j == fim) {
        flag = 1;
    }
    else if (k == fim) {
        flag = 2;
    }

    if (flag == 1) {
        cout << "cw" << endl;
    } else if (flag == 2) {
        cout << "ccw" << endl;
    } else {
        cout << "undefined" << endl;
    }

    return 0;
}
