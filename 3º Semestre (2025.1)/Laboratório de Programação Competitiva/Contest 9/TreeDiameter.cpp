#include <bits/stdc++.h>
using namespace std;

int n, m, diametro;
const int MAX = 2e5 + 1;
vector<int> adj[MAX];
vector<int> altura;

int dfs(int u, int p) {
    int alt1 = 0, alt2 = 0;

    for (auto v : adj[u]) {
        if (v != p) {
            altura[u] = max(altura[u], dfs(v, u));

            if (altura[v] > alt2) {
                alt2 = altura[v];

                if (alt2 > alt1)
                    swap(alt1, alt2);
            }
        }
    }
    diametro = max(diametro, alt1 + alt2);

    return altura[u] += 1;
}

int main() {

    cin >> n;
    m = n - 1;

    altura = vector<int>(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    cout << diametro << endl;
}