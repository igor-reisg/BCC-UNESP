#include <bits/stdc++.h>
using namespace std;

int puloSapo(vector<int>& alt) {
    int n = alt.size() - 1;

    vector<int> dp(n+1);

    dp[1] = 0;
    if (n >= 2) {
        dp[2] = abs(alt[2] - alt[1]);
    }

    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i-1] + abs(alt[i] - alt[i-1]), dp[i-2] + abs(alt[i] - alt[i-2]));
    }
    return dp[n];
}

int main() {
    int n;

    cin >> n;

    vector<int> alt(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> alt[i];
    }

    cout << puloSapo(alt) << endl;
}