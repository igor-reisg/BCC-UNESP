#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll exp(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) res = res * x % m;
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main() {
    ll res, a, b, c;
    int n;
    cin >> n;

    while(n--) {
        cin >> a >> b >> c;

        res = exp(b, c, 1e9 + 7 - 1);
        res = exp(a, res, 1e9 + 7);

        cout << res << endl;
    }
}