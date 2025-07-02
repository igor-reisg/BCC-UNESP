#include <bits/stdc++.h>
using namespace std;

#define MAX 200001

int pai[MAX], tam[MAX];

int find(int x) {
    if (pai[x] == x)
        return x;

    return pai[x] = find(pai[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (tam[x] < tam[y])
        swap(x, y);

    pai[y] = x;
    tam[x] += tam[y];
}

void initDSU(int n) {
    for (int x = 0; x < n; x++) {
        pai[x] = x;
        tam[x] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int j = 1; j <= t; j++) {
        string st;
        int op, x, Q;
        vector<pair<int, char>> q;
        vector<int> resp;
        map<char, int> maxSeg;

        cin >> st;
        int n = st.size();
        initDSU(n);

        cin >> Q;
        for (int i = 0; i < Q; i++) {
            cin >> op >> x;
            
            if (op == 2) {
                q.push_back({x, st[x]});
                st[x] = '#';
            }
            else {
                q.push_back({x, '-'});
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (st[i] == '#') {
                continue;
            }
            if (st[i] == st[i + 1]) {
                unite(i, i + 1);
            }
        }

        for (int i = Q - 1; i >= 0; i--) {
            x = q[i].first;

            if (q[i].second != '-') {
                st[x] = q[i].second;
                if (x - 1 >= 0 && st[x] == st[x - 1]) {
                    unite(x, x - 1);
                }
                if (x + 1 < n && st[x] == st[x + 1]) {
                    unite(x, x + 1);
                }
            }
            else {
                resp.push_back(tam[find(x)]);
            }
        }
        cout << "Case " << j << ':' << '\n';
        for (int i = resp.size() - 1; i >= 0; i--) {
            cout << resp[i] << '\n';
        }
    }
}