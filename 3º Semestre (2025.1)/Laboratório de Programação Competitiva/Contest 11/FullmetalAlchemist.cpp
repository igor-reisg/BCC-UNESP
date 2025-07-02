#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
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
    parent.assign(n, 0);
    len.assign(n, 1);
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int calculaDistancia(int i1, int i2) {
    int maxDif = 0;
    for (int col = 0; col < m; col++) {
        int dif = abs(grid[i1][col] - grid[i2][col]);
        maxDif = max(maxDif, dif);
    }
    return maxDif;
}

int kruskal() {
    initDSU();
    int cost = 0;
    int arestasUsadas = 0;
    
    for (auto [w, u, v] : edges) {
        if (!same(u, v)) {
            unite(u, v);
            cost = max(cost, w);
            arestasUsadas++;
            
            if (arestasUsadas == n - 1) {
                break;
            }
        }
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    grid.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = calculaDistancia(i, j);
            edges.push_back({dist, i, j});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    cout << kruskal() << endl;
}