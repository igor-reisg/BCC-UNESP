#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long left = 1, right = N, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sum = mid * (mid + 1) / 2;

            if (sum <= N) { 
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << ans << endl;
    }
}
