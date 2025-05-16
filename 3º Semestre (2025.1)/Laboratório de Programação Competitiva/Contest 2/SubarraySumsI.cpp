#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long x;

    cin >> n >> x;

    int vet[n];
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    queue<int> q;
    long soma = 0;
    int cont = 0;

    for (int i = 0; i < n; i++) {
        q.push(vet[i]);
        soma += vet[i];

        while(soma > x && !q.empty()) {
            soma -= q.front();
            q.pop();
        }

        if (soma == x) {
            cont++;
        }
    }

    cout << cont << endl;
}
