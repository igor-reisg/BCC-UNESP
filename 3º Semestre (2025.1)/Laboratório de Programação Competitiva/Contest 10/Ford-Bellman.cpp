#include <bits/stdc++.h>

#define MAX 100
#define INF 30000

using namespace std;

int n, m;
vector<int> dist;
vector<tuple<int, int, int>> adj;

void bellmanFord(int s) {
    dist = vector<int>(MAX + 1, INF);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : adj) {
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
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
    }

    bellmanFord(1);

    for (int v = 1; v <= n; v++) {
        if (v != n) 
            cout << dist[v] << " ";
        else
            cout << dist[v];

    }
    cout << "\n";
}