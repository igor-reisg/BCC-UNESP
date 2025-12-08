#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 100

int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> dist;

void dijkstra(int inicio) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[inicio] = 0;
    pq.push({0, inicio});

    while(!pq.empty()) {
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

    for (int i = 0; i < dist.size(); i++) {
        cout << "distância de " << inicio << " até " << i << ": " << dist[i] << endl;
    }
}

int main() {
    cin >> n >> m;

    adj.resize(n);
    dist.resize(n, INF);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dijkstra(0);
}