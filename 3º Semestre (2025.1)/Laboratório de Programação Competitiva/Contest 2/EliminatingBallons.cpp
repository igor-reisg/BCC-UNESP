#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, alt;

    cin >> n;

    unordered_map<int, int> flechas;
    int tiros = 0;

    for (int i = 0; i < n; i++) {
        cin >> alt;

        if (flechas[alt] > 0) {
            flechas[alt]--;
        } else {
            tiros++;
        }

        flechas[alt - 1]++;
    }

    cout << tiros << endl;
}