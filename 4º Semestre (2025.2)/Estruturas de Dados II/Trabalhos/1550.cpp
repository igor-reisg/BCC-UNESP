#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int inverte(int num) {
    int aux = 0;
    while (num > 0) {
        aux = aux * 10 + (num % 10);
        num /= 10;
    }
    return aux;
}

int bfs(int inicio, int fim) {
    vector<bool> vis(10001, false);
    queue<pair<int,int>> q;

    q.push({inicio, 0});
    vis[inicio] = true;

    while (!q.empty()) {
        auto [u, cont] = q.front();
        q.pop();

        if (u == fim) return cont;

        if (u + 1 <= 10000 && !vis[u + 1]) {
            vis[u + 1] = true;
            q.push({u + 1, cont + 1});
        }

        int v = inverte(u);
        if (v <= 10000 && !vis[v]) {
            vis[v] = true;
            q.push({v, cont + 1});
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) <<endl;
    }
    
    return 0;
}
