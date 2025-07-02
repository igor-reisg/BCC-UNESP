#include <bits/stdc++.h>

#define MAX 2500

using namespace std;

const long long INF = 1e9;
bool flag;
int n, m, inicioCiclo = -1;
vector<long long> dist;
vector<int> pai;
vector<tuple<int, int, int>> edges;

void bellmanFord(int s) {
    dist = vector<long long>(MAX + 1, INF);
    pai = vector<int>(n + 1, -1);
    dist[s] = 0;
    pai[s] = s;

    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pai[v] = u;
            }
        }
    }

    flag = false;

    for (auto [u, v, w] : edges) {
        if (dist[u] + w < dist[v]) {
            flag = true;
            inicioCiclo = v;
            pai[v] = u;
            break;
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
        edges.push_back({u, v, w});
    }

    bellmanFord(1);

    if (flag) {
        cout << "YES" << endl;
        
        for (int i = 0; i < n; i++) {
            inicioCiclo = pai[inicioCiclo];
        }
        
        vector<int> caminho;
        int vertice = inicioCiclo;
        
        do {
            caminho.push_back(vertice);
            vertice = pai[vertice];
        } 
        while (vertice != inicioCiclo);
        
        caminho.push_back(inicioCiclo);
        
        reverse(caminho.begin(), caminho.end());
        
        for (int i = 0; i < (int)caminho.size(); i++) {
            if (i > 0) cout << " ";
            cout << caminho[i];
        }
        cout << "\n";
    }
    else
        cout << "NO" << endl;
}