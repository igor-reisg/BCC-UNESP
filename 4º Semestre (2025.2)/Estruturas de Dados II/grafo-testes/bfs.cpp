#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
vector<vector<int>> adj;
vector<int> vis;

void bfs(int inicio) {
    queue<int> q;

    q.push(inicio);
    vis[inicio] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {

    cin >> n >> m;
    
    vis.assign(n, false);
    adj.resize(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++;
            bfs(i);
        }
    }

    cout << count << endl;
}