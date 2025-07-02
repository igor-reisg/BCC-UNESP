#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5;
int n, m;
vector<int> parent, len;
vector<tuple<int, int, int>> edges;

int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return false;

    if (len[x] < len[y])
        swap(x, y);

    parent[y] = x;
    len[x] += len[y];
    return true;
}

void initDSU() {
    parent = len = vector<int>(n + 1);
    for (int u = 1; u <= n; u++) {
        parent[u] = u;
        len[u] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    initDSU();

    int components = n;
    int maxTam = 1;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        if (unite(u, v)) {
            components--;
            maxTam = max(maxTam, len[find(u)]);
        }
        cout << components << " " << maxTam << endl;
    }

}
