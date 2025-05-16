#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, count = 0;

    cin >> n >> k;

    int tempototal = 240;

    tempototal -= k;

    for (int i = 1; i <= n; i++) {
        if (tempototal - (5 * i) >= 0) {
            tempototal -= 5 * i;
            count++;
        }
    }

    cout << count << endl;
}