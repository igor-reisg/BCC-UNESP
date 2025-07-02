#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAX = 1e5 + 1;

int n, m, p, g;
vector<long long> dist_from_p, dist_from_g;
vector<pair<int, int>> adj[MAX];

void dijkstra(int s, vector<long long>& dist) {
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

    cin >> n >> m >> p >> g;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(p, dist_from_p);
    dijkstra(g, dist_from_g);

    vector<int> resposta;
    long long d_pg = dist_from_p[g];

    for (int i = 1; i <= n; i++) {
        if (dist_from_p[i] == 2 * d_pg && dist_from_p[i] == d_pg + dist_from_g[i]) {
            resposta.push_back(i);
        }
    }

    if (resposta.empty()) {
        cout << "*\n";
    } else {
        sort(resposta.begin(), resposta.end());
        for (int i = 0; i < (int)resposta.size(); i++) {
            if (i > 0) cout << " ";
            cout << resposta[i];
        }
        cout << "\n";
    }

    return 0;
}
