#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n, m;
vector<int> adj[MAX];
vector<bool> visitado;
vector<int> caminho;
vector<int> pai;
int inicio = -1, fim = -1;

void dfs(int u, int p) {
    visitado[u] = true;
    pai[u] = p;
    
    for (int i = 0; i < int(adj[u].size()); i++) {
        int v = adj[u][i];
        
        if (v == p) continue;

        if (visitado[v]) {
            inicio = v;
            fim = u;
            return;
        }
        
        dfs(v, u);
        
        if (inicio != -1) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visitado.resize(n + 1, false);
    pai.resize(n + 1, -1);
    
    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            dfs(i, -1);

            if (inicio != -1) 
                break;
        }
    }
    
    if (inicio == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    caminho.push_back(inicio);
    
    int atual = fim;
    while (atual != inicio) {
        caminho.push_back(atual);
        atual = pai[atual];
    }
    
    caminho.push_back(inicio);
    
    cout << caminho.size() << endl;
    for (int u : caminho) {
        cout << u << " ";
    }
    cout << endl;
}