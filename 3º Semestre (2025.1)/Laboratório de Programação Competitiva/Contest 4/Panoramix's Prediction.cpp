#include <bits/stdc++.h>
using namespace std;

bool ehPrimo(int x) {
    for (int i = 2; i < x; i++) {
        if (!(x % i)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m, primo = 0;

    cin >> n >> m;

   for (int i = n + 1; i < m; i++) {
        if(ehPrimo(i)) {
            primo = 1;
        }
    }

    if (!ehPrimo(m) || primo) {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
}