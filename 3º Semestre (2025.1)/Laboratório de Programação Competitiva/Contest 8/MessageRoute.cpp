#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, m;
vector<bool> visitado;
vector<vector<int>> adj;
vector<int> pai;

void bfs(int s) {
    queue<int> q;
    visitado[s] = true;
    pai[s] = -1;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u == n) return;

        for (int v : adj[u]) {
            if (!visitado[v]) {
                visitado[v] = true;
                pai[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.resize(n + 1);
    visitado.resize(n + 1, false);
    pai.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    if (!visitado[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> caminho;
    for (int i = n; i != -1; i = pai[i]) {
        caminho.push_back(i);
    }

    reverse(caminho.begin(), caminho.end());

    cout << caminho.size() << "\n";

    for (int i = 0; i < (int)caminho.size(); i++) {
        cout << caminho[i] << " ";
    }
    cout << "\n";
}