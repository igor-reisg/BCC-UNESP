#include <bits/stdc++.h>

#define MAX 501

using namespace std;

const long long INF = 1e15;
int n, m, q;
long long adj[MAX][MAX], dist[MAX][MAX];

void floydWarshall() {
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (u == v)
                dist[u][v] = 0;
            else if (adj[u][v] != 0)
                dist[u][v] = adj[u][v];
            else
                dist[u][v] = INF;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (dist[u][k] + dist[k][v] < dist[u][v])
                    dist[u][v] = dist[u][k] + dist[k][v];
            }
        }
    }
}

void addEdge(int u, int v, long long w) {
    if (adj[u][v] == 0)
        adj[u][v] = adj[v][u] = w;
    else
        adj[u][v] = adj[v][u] = min(adj[u][v], w);
}

void initGraph() {
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            adj[u][v] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    initGraph();

    for (int i = 0; i < m; i++) {
        int u, v; 
        long long w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    floydWarshall();

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (dist[a][b] >= INF)
            cout << -1 << "\n";
        else
            cout << dist[a][b] << "\n";
    }
}
