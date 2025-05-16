#include <bits/stdc++.h>
using namespace std;

const int MAX = 10e7;

int qtdmin(int n) {
    vector<int> dp(n + 1, MAX);
    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
        string str = to_string(i);

        for (char c : str) {
            int digito = c - '0';
            if (digito > 0) {
                dp[i] = min(dp[i], dp[i - digito] + 1);
            }
        }
    }
    return dp[n];
}

int main() {
    int n;

    cin >> n;

    cout << qtdmin(n) << endl;
}