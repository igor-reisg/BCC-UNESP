#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAX = 1e5 + 1;

int n, m;
vector<long long> dist;
vector<int> pai;
vector<pair<int, int>> adj[MAX];

void dijkstra(int s) {
    dist = vector<long long>(n + 1, INF);
    pai = vector<int>(n + 1, -1);

    dist[s] = 0;
    pai[s] = s;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pai[v] = u;
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
        adj[v].push_back({u, w});
    }

    dijkstra(1);

    if (dist[n] == INF) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> caminho;
    for (int i = n; i != pai[i]; i = pai[i]) {
        caminho.push_back(i);
    }
    caminho.push_back(1);

    reverse(caminho.begin(), caminho.end());

    for (int i = 0; i < (int)caminho.size(); i++) {
        if (i > 0) 
            cout << " ";
        cout << caminho[i];
    }
    cout << "\n";
}
