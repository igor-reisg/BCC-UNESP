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

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (len[x] < len[y])
        swap(x, y);

    parent[y] = x;
    len[x] += len[y];
}

void initDSU() {
    parent = len = vector<int>(n + 1);
    for (int u = 1; u <= n; u++) {
        parent[u] = u;
        len[u] = 1;
    }
}

long long kruskal() {
    long long cost = 0;
    int components = n;

    initDSU();

    for (auto [w, u, v] : edges) {
        if (!same(u, v)) {
            unite(u, v);
            cost += w;
            components--;
        }
    }

    if (components > 1)
        return -1;

    return cost;
}

void addEdge(int u, int v, int w) {
    edges.push_back({w, u, v});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    sort(begin(edges), end(edges));

    long long res = kruskal();

    if (res == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << res << endl;

}