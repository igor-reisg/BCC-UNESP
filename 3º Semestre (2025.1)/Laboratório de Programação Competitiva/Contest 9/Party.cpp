#include <bits/stdc++.h>
using namespace std;

int n, maxProf = 0;
const int MAX = 2005;
vector<int> adj[MAX];
bool visitado[MAX];

void dfs(int u, int prof) {
    maxProf = max(maxProf, prof);

    for (int v : adj[u]) {
        dfs(v, prof + 1);
    }
}

int main() {
    
    cin >> n;
    vector<int> subordinados;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        if (p == -1)
            subordinados.push_back(i + 1);
        else
            adj[p].push_back(i + 1);
    }

    for (int sub : subordinados) {
        dfs(sub, 1);
    }

    cout << maxProf << endl;
}