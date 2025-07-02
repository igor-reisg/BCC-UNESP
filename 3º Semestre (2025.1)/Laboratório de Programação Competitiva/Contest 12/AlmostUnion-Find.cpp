#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const int MAXVIR = 4 * MAX;

int n, m, cont;
int pai[MAXVIR], tam[MAXVIR], soma[MAXVIR], pos[MAX];

int find(int x) {
    if (pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void unite(int p, int q) {
    int x = find(pos[p]);
    int y = find(pos[q]);

    if (x == y) return;

    if (tam[x] < tam[y]) swap(x, y);

    pai[y] = x;
    tam[x] += tam[y];
    soma[x] += soma[y];
}

void initDSU() {
    cont = 2 * n + 1;

    for (int x = 1; x <= n; x++) {
        int id = x + n;
        pai[id] = id;
        tam[id] = 1;
        soma[id] = x;
        pos[x] = id;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m) {
        initDSU();

        for (int i = 0; i < m; i++) {
            int op, p, q;
            cin >> op >> p;

            if (op == 3) {
                int r = find(pos[p]);
                cout << tam[r] << " " << soma[r] << '\n';
            } 
            else {
                cin >> q;
                if (op == 1) {
                    unite(p, q);
                } 
                else if (op == 2) {
                    int x = find(pos[p]);
                    int y = find(pos[q]);
                    
                    if (x == y) continue;

                    tam[x]--;
                    soma[x] -= p;

                    int id = cont++;
                    pai[id] = id;
                    tam[id] = 1;
                    soma[id] = p;
                    pos[p] = id;

                    unite(p, q);
                }
            }
        }
    }
}
