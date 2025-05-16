#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string fila[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    cin >> n;

    while (n > 5) {
        n = n / 2;
        n -= 2;
    }
        
    cout << fila[n - 1] << endl;

    return 0;
}