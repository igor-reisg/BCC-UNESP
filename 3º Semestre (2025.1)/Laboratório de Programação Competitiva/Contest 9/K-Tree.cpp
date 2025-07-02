#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

int contar_caminhos(int soma_max, int peso_max) {
    vector<int> dp(soma_max + 1, 0);
    dp[0] = 1;

    for (int soma = 1; soma <= soma_max; soma++) {
        for (int peso = 1; peso <= peso_max; peso++) {
            if (soma - peso >= 0) {
                dp[soma] = (dp[soma] + dp[soma - peso]) % MOD;
            }
        }
    }

    return dp[soma_max];
}

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    int total = contar_caminhos(n, k);

    int abaixo = contar_caminhos(n, d - 1);

    int resposta = (total - abaixo + MOD) % MOD;

    cout << resposta << endl;
}
