#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAX = 100005;
vector<int> adj[MAX];
bool visitado[MAX];

double dfs(int u) {
    visitado[u] = true;
    int cidades = 0;
    double soma = 0.0;

    for (int v : adj[u]) {
        if(!visitado[v]) {
            cidades++;
            soma += dfs(v);
        }
    }

    if (cidades == 0) return 0.0;

    return soma / cidades + 1;
}

int main() {
    cin >> n;
    m = n - 1;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    double media = dfs(1);

    cout << fixed << setprecision(15) << media << endl;
}