#include <bits/stdc++.h>
using namespace std;

int maxPaginas(int n, int x, vector<int>& h, vector<int>& s) {
    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    cout << maxPaginas(n, x, h, s) << endl;
}