#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, pairs = 0, num;
    cin >> n >> k;

    unordered_set<int> valores;

    for (int i = 0; i < n; i++) {
        cin >> num;

        if (valores.count(num - k)) pairs++;
        if (valores.count(num + k)) pairs++;

        valores.insert(num);
    }

    cout << pairs << endl;
    
    return 0;
}
