#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;
        
        vector<int> pessoas(n);
        int minpessoas = n, maxprov = 1, maxpessoas = 1;

        for (int i = 0; i < n; i++) {
            cin >> pessoas[i];
        }

        for(int i = 1; i < n; i++) {
            if (pessoas[i] - pessoas[i - 1] <= 2) {
                maxprov++;
            }
            else {
                minpessoas = min(minpessoas, maxprov);
                maxpessoas = max(maxpessoas, maxprov);
                maxprov = 1;
            }
        }

        minpessoas = min(minpessoas, maxprov);
        maxpessoas = max(maxpessoas, maxprov);

        cout << minpessoas << " " << maxpessoas << endl;
    }
}