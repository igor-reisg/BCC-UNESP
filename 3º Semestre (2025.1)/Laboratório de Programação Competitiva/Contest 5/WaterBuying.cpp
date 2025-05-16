#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;

    cin >> q;
    while(q--) {
        long long int n;
        int a, b;
        long long custo;
        cin >> n >> a >> b;

        if(b < 2*a) {
            custo = (n / 2) * b + (n % 2) * a;
        }
        else
            custo = n * a;

        cout << custo << endl;
    }
}