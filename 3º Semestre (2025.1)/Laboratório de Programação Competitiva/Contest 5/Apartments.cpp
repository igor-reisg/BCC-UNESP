#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> apts(n), tams(m);

    for (int i = 0; i < n; i++) {
        cin >> apts[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> tams[i];
    }

    sort(apts.begin(), apts.end());
    sort(tams.begin(), tams.end());

    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        if(tams[j] < apts[i] - k) j++;
        else if (tams[j] > apts[i] + k) i++;
        else {
            count++;
            i++;
            j++;
        }
    }

    cout << count << endl;    
}