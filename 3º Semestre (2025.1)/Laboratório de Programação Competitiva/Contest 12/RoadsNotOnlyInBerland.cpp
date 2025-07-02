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

    cin >> n;

    initDSU();

    vector<pair<int, int>> extra;
    vector<pair<int, int>> conexao;

    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (same(a, b)) {
            extra.push_back({a, b});
        }
        else
            unite(a, b);
    }

    for (int i = 1; i <= n; i++) {
        if (!same(1, i)) {
            conexao.push_back({1, i});
            unite(1, i);
        }
    }

    cout << conexao.size() << '\n';
    for (int i = 0; i < (int)conexao.size(); i++) {
        cout << extra[i].first << " " << extra[i].second << " " << conexao[i].first << " " << conexao[i].second << '\n';
    }
}