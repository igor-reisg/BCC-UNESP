#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    vector<int> dp(n);
    dp[0] = array[0];

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + array[i];
    }

    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;

        if (i == 0) {
            cout << dp[j] << endl;
        } else {
            cout << dp[j] - dp[i - 1] << endl;
        }
    }
}
