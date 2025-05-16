#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, m;
vector<int> irmaos;
vector<int> adj[MAX];

bool bfs(int s) {
    queue<int> q;
    irmaos[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (irmaos[v] == 0) {
                irmaos[v] = 3 - irmaos[u];
                q.push(v);
            }
            else if (irmaos[v] == irmaos[u])
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;

    cin >> n >> m;
    irmaos.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (irmaos[i] == 0) {
            if (!bfs(i)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << irmaos[i] << " ";
    }
    cout << endl;

}