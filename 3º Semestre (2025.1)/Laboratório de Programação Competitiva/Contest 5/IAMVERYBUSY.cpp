#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, m, n;
        cin >> N;

        vector<pair<int, int>> atividades;
        for (int i = 0; i < N; i++) {
            cin >> m >> n;
            atividades.push_back({n, m});
        }

        sort(atividades.begin(), atividades.end());

        int count = 0, ultimoFim = -1;
        for (auto atividade : atividades) {
            int fim = atividade.first;
            int inicio = atividade.second;

            if (inicio >= ultimoFim) {
                count++;
                ultimoFim = fim;
            }
        }
        cout << count << endl;
    }
}
