#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAX = 1e5 + 5;

int n, m;
vector<pair<int, int>> adj[MAX];
long long dist[MAX][2];

void dijkstra(int s) {
    for (int i = 1; i <= n; ++i) {
        dist[i][0] = dist[i][1] = INF;
    }

    dist[s][0] = 0;
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
    pq.push({0, s, 0});

    while (!pq.empty()) {
        auto [custo, u, usado] = pq.top();
        pq.pop();

        if (custo > dist[u][usado]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v][usado] > dist[u][usado] + w) {
                dist[v][usado] = dist[u][usado] + w;
                pq.push({dist[v][usado], v, usado});
            }

            if (!usado && dist[v][1] > dist[u][0] + w / 2) {
                dist[v][1] = dist[u][0] + w / 2;
                pq.push({dist[v][1], v, 1});
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

    cout << dist[n][1] << '\n';
}
