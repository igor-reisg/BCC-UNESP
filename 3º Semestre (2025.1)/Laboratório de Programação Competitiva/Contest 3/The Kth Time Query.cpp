#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;

    cin >> n >> q;

    vector<int> vet(n);

    unordered_map<int, vector<int>> posicoes;

    for(int i = 0; i < n; i++) {
        cin >> vet[i];
        posicoes[vet[i]].push_back(i + 1);
    }

    while (q--) {
        int x, k;

        cin >> x >> k;

        if (posicoes.find(x) != posicoes.end() && posicoes[x].size() >= (unsigned int)k) {
            cout << posicoes[x][k - 1] << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}