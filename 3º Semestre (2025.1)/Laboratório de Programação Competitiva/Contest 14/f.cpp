#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, m, k;
int a[N], f[N];
int g[N][N];
int ans;

void checkmax(int &x, int y) {
    if (y > x) x = y;
}

void checkmin(int &x, int y) {
    if (y < x) x = y;
}

void solve() {
    cin >> n;
    m = 0;
    k = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        k = g[k][a[i]];
    }

    fill(f, f + N, 0x3f3f3f3f);
    for (int i = 1; i <= n; i++) {
        a[i] /= k;
        checkmax(m, a[i]);
        f[a[i]] = 0;
    }

    for (int x = m; x >= 1; x--) {
        for (int i = 1; i <= n; i++) {
            int y = a[i];
            checkmin(f[g[x][y]], f[x] + 1);
        }
    }

    ans = max(f[1] - 1, 0);
    for (int i = 1; i <= n; i++) {
        if (a[i] > 1) ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int x = 0; x < N; x++) {
        g[x][0] = g[0][x] = g[x][x] = x;
    }
    for (int x = 1; x < N; x++) {
        for (int y = 1; y < x; y++) {
            g[x][y] = g[y][x] = g[y][x % y];
        }
    }

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
