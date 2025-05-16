#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int *pares = new int[n], *impares = new int[n];
    int qtdpar = 0, qtdimpar = 0;

    for (int i = 1; i <= n; i += 2) {
        impares[qtdimpar++] = i;
    }

    for (int i = 2; i <= n; i += 2) {
        pares[qtdpar++] = i;
    }

    for (int i = 0; i < qtdpar; i++) {
        cout << pares[i] << " ";
    }

    for (int i = 0; i < qtdimpar; i++) {
        cout << impares[i] << " ";
    }

    cout << endl;

    delete[] pares;
    delete[] impares;

    return 0;
}
