#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;
const int MOD_FIB = 998244352;

void mult(int a[2][2], int b[2][2], int m) {
    int res[2][2];
    res[0][0] = (a[0][0] * b[0][0] % m + a[0][1] * b[1][0] % m) % m;
    res[0][1] = (a[0][0] * b[0][1] % m + a[0][1] * b[1][1] % m) % m;
    res[1][0] = (a[1][0] * b[0][0] % m + a[1][1] * b[1][0] % m) % m;
    res[1][1] = (a[1][0] * b[0][1] % m + a[1][1] * b[1][1] % m) % m;
    a[0][0] = res[0][0];
    a[0][1] = res[0][1];
    a[1][0] = res[1][0];
    a[1][1] = res[1][1];
}

int fib(int n, int m) {
    if (n == 0) return 0;
    int F[2][2] = {{1, 1}, {1, 0}};
    int res[2][2] = {{1, 0}, {0, 1}};

    n--;
    while (n > 0) {
        if (n % 2)
            mult(res, F, m);
        mult(F, F, m);
        n /= 2;
    }
    return res[0][0];
}

int modpow(int base, int exp, int m) {
    int res = 1;
    base %= m;
    while (exp > 0) {
        if (exp & 1)
            res = res * base % m;
        base = base * base % m;
        exp >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int eN = fib(N, MOD_FIB);
    int ans = modpow(2, eN, MOD);

    cout << ans << "\n";
}
