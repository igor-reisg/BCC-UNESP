#include <bits/stdc++.h>
using namespace std;

vector<int> pai, tam;
int n, k;

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
    pai = tam = vector<int>(3 * n + 1);
    for (int i = 1; i <= 3 * n; i++) {
        pai[i] = i;
        tam[i] = 1;
    }
}

int presa(int x) {
    return x + n;
}

int predador(int x) {
    return x + 2 * n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;

        initDSU();
        int falsos = 0;

        for (int i = 0; i < k; i++) {
            int d, x, y;
            cin >> d >> x >> y;

            if (x > n || y > n || x <= 0 || y <= 0) {
                falsos++;
                continue;
            }

            if (d == 1) {
                if (same(x, presa(y)) || same(x, predador(y))) {
                    falsos++;
                    continue;
                }

                unite(x, y);
                unite(presa(x), presa(y));
                unite(predador(x), predador(y));
            }
            else if (d == 2) {
                if (x == y || same(x, y) || same(x, presa(y))) {
                    falsos++;
                    continue;
                }

                unite(x, predador(y));
                unite(presa(x), y);
                unite(predador(x), presa(y));
            }
        }

        cout << falsos << '\n';
    }
}
