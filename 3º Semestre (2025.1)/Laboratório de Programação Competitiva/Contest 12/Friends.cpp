#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> pai, tam;

int find(int x) {
    if (pai[x] == x)
        return x;

    return pai[x] = find(pai[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (tam[x] < tam[y])
        swap(x, y);

    pai[y] = x;
    tam[x] += tam[y];
}

void initDSU() {
    pai = tam = vector<int>(n + 1);

    for (int x = 1; x <= n; x++) {
        pai[x] = x;
        tam[x] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        initDSU();

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            unite(a, b);
        }

        int maior = 0;
        for (int i = 1; i <= n; i++) {
            if (pai[i] == i)
                maior = max(maior, tam[i]);
        }

        cout << maior << '\n';
    }
}