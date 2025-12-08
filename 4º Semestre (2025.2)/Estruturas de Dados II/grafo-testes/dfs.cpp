#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int inicio) {
    vis[inicio] = true;

    for (int v : adj[inicio]) {
        if (!vis[v])
            dfs(v);
    }
}

int main() {

    cin >> n >> m;

    adj.resize(n);
    vis.assign(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++;
            dfs(i);
        }
    }

    cout << count << endl;
    
}