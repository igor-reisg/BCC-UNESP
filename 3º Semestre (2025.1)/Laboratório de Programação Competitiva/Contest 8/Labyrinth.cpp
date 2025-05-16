#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int m, n;
string labirinto[MAX];
bool visitado[MAX][MAX];
pair<int, int> pai[MAX][MAX];
pair<int, int> inicio, fim;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char direcao[4] = {'U', 'D', 'L', 'R'};

void initLabirinto() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            visitado[i][j] = false;
        }
    }
}

void bfs(pair<int, int> inicio) {
    int qtdDirecoes = 4;
    queue<pair<int, int>> q;

    visitado[inicio.first][inicio.second] = true;
    q.push(inicio);

    while (!q.empty()) {
        pair<int, int> atual = q.front();
        q.pop();

        for (int i = 0; i < qtdDirecoes; i++) {
            int novoDY = atual.first + dy[i];
            int novoDX = atual.second + dx[i];

            if (novoDY >= 0 && novoDY < n && novoDX >= 0 && novoDX < m && labirinto[novoDY][novoDX] != '#' && !visitado[novoDY][novoDX]) {
                visitado[novoDY][novoDX] = true;
                pai[novoDY][novoDX] = atual;
                q.push({novoDY, novoDX});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> labirinto[i];
        for (int j = 0; j < m; j++) {
            if (labirinto[i][j] == 'A') inicio = {i, j};
            if (labirinto[i][j] == 'B') fim = {i, j};
        }
    }

    initLabirinto();
    
    bfs(inicio);

    if (!visitado[fim.first][fim.second]) {
        cout << "NO" << endl;
    } 
    else {
        cout << "YES" << endl;

        string caminho;
        pair<int, int> atual = fim;

        while (atual != inicio) {
            pair<int, int> ant = pai[atual.first][atual.second];
            for (int i = 0; i < 4; i++) {
                if (ant.first + dy[i] == atual.first && ant.second + dx[i] == atual.second) {
                    caminho.push_back(direcao[i]);
                    break;
                }
            }
            atual = ant;
        }

        reverse(caminho.begin(), caminho.end());

        cout << caminho.length() << endl;
        cout << caminho << endl;
    }
}
