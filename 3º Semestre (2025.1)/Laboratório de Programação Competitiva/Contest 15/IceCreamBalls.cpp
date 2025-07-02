#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        auto check = [&](ll x) {
            return x * (x - 1LL) / 2LL;
        };

        ll esq = 0, dir = 2e9;
        ll ans;

        while(esq <= dir) {
            ll mid = esq + (dir - esq) / 2LL;
            
            if(check(mid) > n) {
                dir = mid - 1;
            } 
            else {
                esq = mid + 1;
                ans = mid;
            }
        }
        cout << ans + (n - check(ans)) << '\n';
    }
}