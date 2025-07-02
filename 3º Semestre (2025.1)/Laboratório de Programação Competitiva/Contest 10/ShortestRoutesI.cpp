#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAX = 1e5 + 1;

int n, m;
vector<long long> dist;
vector<pair<int, int>> adj[MAX];

void dijkstra(int s) {
    dist = vector<long long>(n + 1, INF);
    dist[s] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
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
        adj[u].push_back({v, w});
    }

    dijkstra(1);

    for (int v = 1; v <= n; v++) {
        if (v != n) 
            cout << dist[v] << " ";
        else
            cout << dist[v];
    }
    cout << "\n";
}
