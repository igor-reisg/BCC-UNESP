#include <bits/stdc++.h>
using namespace std;

int menorDiferenca = INT_MAX;

void backtracking(vector<int>& pedras, int i, int pote1, int pote2) {
    if((unsigned int)i == pedras.size()) {
        int diff = abs(pote1 - pote2);
        menorDiferenca = min(diff, menorDiferenca);
        return;
    }

    backtracking(pedras, i + 1, pote1 + pedras[i], pote2);

    backtracking(pedras, i + 1, pote1, pote2 + pedras[i]);
}

int main() {
    int n;

    cin >> n;

    vector<int> pedras(n);
    for (int i = 0; i < n; i++) {
        cin >> pedras[i];
    }

    backtracking(pedras, 0, 0, 0);

    cout << menorDiferenca << endl;
}