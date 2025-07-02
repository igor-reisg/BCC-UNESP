#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAX = 100005;
vector<int> adj[MAX];
bool visitado[MAX];

void dfs(int u){
    visitado[u] = true;

    for(int v : adj[u]) {
        if(!visitado[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    if (m != n){
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; i++){
        if(!visitado[i]){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "FHTAGN!" << endl;
}