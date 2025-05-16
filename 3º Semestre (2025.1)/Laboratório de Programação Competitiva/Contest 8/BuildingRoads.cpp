#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int m, n;
bool vis[MAX];
vector<int> adj[MAX];
vector<int> representantes;

void bfs(int s) {
    queue<int> q;
    vis[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); 
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            representantes.push_back(i);
            bfs(i);
        }
    }

    int j = representantes.size() - 1;
    cout << j << endl;

    for (unsigned int i = 1; i < representantes.size(); i++) {
        cout << representantes[i - 1] << " " << representantes[i] << endl;
    }
}