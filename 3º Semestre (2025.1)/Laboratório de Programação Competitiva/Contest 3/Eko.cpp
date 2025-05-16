#include <bits/stdc++.h>
using namespace std;

long long calcularMadeira(vector<int>& arvores, int altura) {
    long long madeira = 0;
    for (int arvore : arvores) {
        if (arvore > altura) {
            madeira += (arvore - altura);
        }
    }
    return madeira;
}

int main() {
    int N;
    long long M;
    
    cin >> N >> M;

    vector<int> arvores(N);
    int maxAltura = 0;

    for (int i = 0; i < N; i++) {
        cin >> arvores[i];
        maxAltura = max(maxAltura, arvores[i]);
    }

    int left = 0, right = maxAltura, resposta = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long madeiraCortada = calcularMadeira(arvores, mid);

        if (madeiraCortada >= M) { 
            resposta = mid;
            left = mid + 1;
        } 
        else 
            right = mid - 1;
    }
    
    cout << resposta << endl;
}