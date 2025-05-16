#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> barras(n);

    for (int i = 0; i < n; i++) {
        cin >> barras[i];
    }

    map<int, int> count;

    for (int i = 0; i < n; i++) {
        count[barras[i]]++;
    }

    int maiortorre = 0, totaltorres = count.size();

    for (auto p : count) {
        if (p.second > maiortorre) {
            maiortorre = p.second;
        }
    }

    cout << maiortorre << " " << totaltorres << endl;
}