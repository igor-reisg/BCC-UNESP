#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;

    while (k--) {
        long long n, x, t;
        cin >> n >> x >> t;

        long long d = min(n - 1, t / x);

        long long instatisfacao = (n - d) * d + (d * (d - 1)) / 2;

        cout << instatisfacao << '\n';
    }
}
