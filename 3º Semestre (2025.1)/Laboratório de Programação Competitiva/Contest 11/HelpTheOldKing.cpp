#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> parent, len;
vector<tuple<int, int, int>> edges;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (len[x] < len[y]) swap(x, y);

    parent[y] = x;
    len[x] += len[y];
}

void initDSU() {
    parent.assign(n + 1, 0);
    len.assign(n + 1, 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

long long kruskal() {
    long long somaExp = 0;
    int arestasUsadas = 0;

    for (auto [w, u, v] : edges) {
        if (!same(u, v)) {
            unite(u, v);
            somaExp += w;
            arestasUsadas++;
            if (arestasUsadas == n - 1) 
                break;
        }
    }

    if (arestasUsadas != n - 1) 
        return -1;

    return somaExp + 1;
}

int getExp(long long cost) {
    int exp = 0;
    while (cost % 2 == 0) {
        cost /= 2;
        exp++;
    }
    return exp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    while (T--) {
        cin >> n >> m;
        
        initDSU();
        edges.clear();

        for (int i = 0; i < m; i++) {
            int u, v;
            long long c;
            cin >> u >> v >> c;

            int exp = getExp(c);
            edges.push_back({exp, u, v});
        }

        sort(edges.begin(), edges.end());

        cout << kruskal() << endl;
    }
}
