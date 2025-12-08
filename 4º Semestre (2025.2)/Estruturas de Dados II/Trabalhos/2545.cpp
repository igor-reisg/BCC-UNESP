#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    
    while (cin >> n) {
        vector<vector<int>> adj(n + 1);
        vector<int> grau(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> x;
                adj[x].push_back(i);
                grau[i]++;
            }
        }

        queue<int> q;
        vector<int> tempo(n + 1, 0);

        for (int i = 1; i <= n; i++)
            if (grau[i] == 0) {
                q.push(i);
                tempo[i] = 1;
            }

        int tempoMax = 0;
        int cont = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cont++;
            tempoMax = max(tempoMax, tempo[u]);

            for (int v : adj[u]) {
                grau[v]--;
                if (grau[v] == 0) {
                    tempo[v] = tempo[u] + 1;
                    q.push(v);
                }
            }
        }

        if (cont != n) cout << -1 << endl;
        else cout << tempoMax << endl;
    }
}
