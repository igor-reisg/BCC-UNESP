#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> parent, len;
vector<tuple<int, int, int>> edges;
vector<tuple<int, int, int>> mstEdges;
map<pair<int, int>, int> edgeCost;
int mstTotalCost;

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

void buildOriginalMST() {
    initDSU();
    mstTotalCost = 0;
    
    for (auto [w, u, v] : edges) {
        if (!same(u, v)) {
            unite(u, v);
            mstTotalCost += w;
            mstEdges.push_back({w, u, v});
        }
    }
}

int kruskal(int U, int V) {
    pair<int, int> queryEdge = {min(U, V), max(U, V)};
    
    for (auto [w, u, v] : mstEdges) {
        if ((u == U && v == V) || (u == V && v == U)) {
            return mstTotalCost;
        }
    }
    
    initDSU();
    int cost = edgeCost[queryEdge];
    unite(U, V);
    
    for (auto [w, u, v] : mstEdges) {
        if (!same(u, v)) {
            unite(u, v);
            cost += w;
        }
    }
    
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
        edgeCost[{min(u, v), max(u, v)}] = w;
    }
    
    sort(edges.begin(), edges.end());
    buildOriginalMST();
    
    int q;
    cin >> q;
    
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << kruskal(u, v) << "\n";
    }
}