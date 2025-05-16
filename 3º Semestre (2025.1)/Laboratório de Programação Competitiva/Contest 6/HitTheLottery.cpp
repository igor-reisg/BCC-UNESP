#include <bits/stdc++.h>
using namespace std;

vector<int> notas = {1, 5, 10, 20, 100};

long long troco(int n, vector<long long>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    long long val = LLONG_MAX - 1;
    for (auto nota : notas) {
        if (n - nota < 0) continue;
        val = min(troco(n - nota, dp) + 1, val);
    }
    
    dp[n] = val;
    return dp[n];
}

int main() {
    long long n;
    cin >> n;
    
    int MAX_CALC = 10000;
    
    if (n <= MAX_CALC) {
        vector<long long> dp(n + 1, -1);
        cout << troco(n, dp) << endl;
        return 0;
    }
    
    vector<long long> dp(MAX_CALC + 1, -1);
    long long valor_100 = troco(100, dp);
    long long resto = n % 100;
    
    long long resultado = (n / 100) * valor_100 + troco(resto, dp);
    
    cout << resultado << endl;
}