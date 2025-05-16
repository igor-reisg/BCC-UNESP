#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, c, d; 
    cin >> a >> b >> c >> d;
	
    int w = c-a, h = 100000;

	if (b-a != 1) {
        cout << "-1\n"; 
        return;
    }
	if (d-c != 1) {
        cout << "-1\n"; 
        return;
    }
	if (c-a != w) {
        cout << "-1\n"; 
        return;
    }
	if (d-b != w) {
        cout << "-1\n"; 
        return;
    }
	if (w <= 1) {
        cout << "-1\n"; 
        return;
    }
	if (a % w == 0) {
        cout << "-1\n"; 
        return;
    }
    
	cout << h << ' ' << w << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}