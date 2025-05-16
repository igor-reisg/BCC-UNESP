#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd;
    cin >> qtd;

    vector<ll> a(qtd);
    for (int i = 0; i < qtd; i++) {
        cin >> a[i];
    }

    int n = a.size();
    vector<vector<ll>> dp(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }

    for (int tam = 2; tam <= n; tam++) {
        for (int esq = 0; esq + tam - 1 < n; esq++) {
            int dir = esq + tam - 1;

            ll pegaEsq = a[esq] - dp[esq + 1][dir];
            ll pegaDir = a[dir] - dp[esq][dir - 1];

            dp[esq][dir] = max(pegaEsq, pegaDir);
        }
    }
    cout << dp[0][n-1] << endl;
}