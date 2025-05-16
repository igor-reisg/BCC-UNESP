#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& principe, vector<int>& princesa) {
    unordered_map<int, int> pos;
    
    for (int i = 0; i < (int)princesa.size(); i++) {
        pos[princesa[i]] = i;
    }

    vector<int> seq;
    for (int val : principe) {
        if (pos.count(val)) {
            seq.push_back(pos[val]);
        }
    }

    vector<int> lis;
    for (int x : seq) {
        auto it = lower_bound(lis.begin(), lis.end(), x);

        if (it == lis.end()) 
            lis.push_back(x);
        else 
            *it = x;
    }
    return (int)lis.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, p, q;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> n >> p >> q;
        
        vector<int> principe(p + 1), princesa(q + 1);
        
        for (int j = 0; j <= p; j++) 
            cin >> principe[j];
        
        for (int j = 0; j <= q; j++) 
            cin >> princesa[j];

        cout << "Case " << i << ": " << lis(principe, princesa) << endl;
    }
}
