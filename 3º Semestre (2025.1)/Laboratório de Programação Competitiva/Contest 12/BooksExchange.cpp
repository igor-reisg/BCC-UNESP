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

    int q;
    cin >> q;

    while (q--) {
        cin >> n;

        initDSU();

        vector<int> p(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        for (int i = 1; i <= n; i++) {
            unite(i, p[i]);
        }

        for (int i = 1; i <= n; i++) {
            cout << tam[find(i)] << " ";
        }
        cout << '\n';
    }
}