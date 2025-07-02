#include <bits/stdc++.h>

#define MAX 2500
using namespace std;

const long long INF = 1e18;
int n, m;
vector<long long> dist;
vector<tuple<int, int, int>> adj;
vector<vector<int>> grafo(MAX + 1);
vector<bool> visitado(MAX + 1);

void dfs(int u) {
    visitado[u] = true;

    for (int v : grafo[u]) {
        if (!visitado[v])
            dfs(v);
    }
}

void bellmanFord(int s) {
    dist = vector<long long>(MAX + 1, -INF);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : adj) {
            if (dist[u] != -INF && dist[u] + w > dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (auto [u, v, w] : adj) {
        if (dist[u] != -INF && dist[u] + w > dist[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
        grafo[u].push_back(v);
    }

    bellmanFord(1);

    if (visitado[n])
        cout << -1 << "\n";
    else
        cout << dist[n] << "\n";
}
