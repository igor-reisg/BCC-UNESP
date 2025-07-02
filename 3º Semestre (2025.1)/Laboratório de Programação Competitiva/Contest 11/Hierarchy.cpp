#include <bits/stdc++.h>

#define MAX 1000
#define INF 1e9

using namespace std;

int n, m;
vector<pair<int, int>> adj[MAX + 1];

int findMinCostArborescence(int root) {
    vector<int> minCost(n + 1, INF);
    vector<int> parent(n + 1, -1);
    
    minCost[root] = 0;
    
    for (int u = 1; u <= n; u++) {
        for (auto [v, cost] : adj[u]) {
            if (v != root && cost < minCost[v]) {
                minCost[v] = cost;
                parent[v] = u;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (i != root && minCost[i] == INF) {
            return -1;
        }
    }
    
    int cost = 0;
    for (int i = 1; i <= n; i++) {
        if (i != root) {
            cost += minCost[i];
        }
    }
    
    return cost;
}

void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<int> q(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }

    int raiz = -1;
    int maxQual = -1;
    for (int i = 1; i <= n; i++) {
        if (q[i] > maxQual) {
            maxQual = q[i];
            raiz = i;
        }
    }

    int countMax = 0;
    for (int i = 1; i <= n; i++) {
        if (q[i] == maxQual) {
            countMax++;
        }
    }

    if (countMax > 1) {
        cout << -1 << endl;
        return 0;
    }

    cout << findMinCostArborescence(raiz) << endl;
    return 0;
}