#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll combinacoes(ll n, ll x, vector<ll>& coins) {
    ll dp[x + 1] = {};
    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] > i) continue;
            dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
        }
    }
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << combinacoes(n, x, coins) << endl;
}
