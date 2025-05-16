#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, horas;
    cin >> n >> k;

    int water[n];
    for (int i = 0; i < n; i++) {
        cin >> water[i];
    }

    int min = k;

    for (int i = 0; i < n; i++) {
        if (k % water[i] == 0) {
            horas = k / water[i];
            if (horas < min) {
                min = horas;
            }
        }
    }

    cout << min << endl;

    return 0;
}
