#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct No {
    No* filho[26];
    bool fim;
    No() : fim(false) {
        for (int i = 0; i < 26; i++) {
            filho[i] = nullptr;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    int k;
    cin >> s >> k;
    
    No* raiz = new No();
    int tamanhomax = 0;
    for (int i = 0; i < k; i++) {
        string palavra;
        cin >> palavra;
        if (palavra.size() > tamanhomax) {
            tamanhomax = palavra.size();
        }
        No* cur = raiz;
        for (char c : palavra) {
            int idx = c - 'a';
            if (cur->filho[idx] == nullptr) {
                cur->filho[idx] = new No();
            }
            cur = cur->filho[idx];
        }
        cur->fim = true;
    }
    
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        if (dp[i] == 0) continue;
        No* cur = raiz;
        for (int j = i; j < min(i + tamanhomax, n); j++) {
            int idx = s[j] - 'a';
            if (cur->filho[idx] == nullptr) {
                break;
            }
            cur = cur->filho[idx];
            if (cur->fim) {
                dp[j+1] = (dp[j+1] + dp[i]) % MOD;
            }
        }
    }
    
    cout << dp[n] << '\n';
    
    return 0;
}