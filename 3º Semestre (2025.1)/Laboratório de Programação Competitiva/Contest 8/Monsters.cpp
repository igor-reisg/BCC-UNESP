#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char dir[] = {'U', 'D', 'R', 'L'};

int direction[1005][1005];

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &row : grid) {
        cin >> row;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            direction[i][j] = -2;

    queue<pair<int, int>> q;
    int ax = -1, ay = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
            } else if (grid[i][j] == 'A') {
                ax = i;
                ay = j;
            }
        }
    }

    q.push({ax, ay});
    direction[ax][ay] = -1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (grid[x][y] == 'A' && (x == 0 || x == n - 1 || y == 0 || y == m - 1)) {
            cout << "YES\n";
            string path;
            int cx = x, cy = y;
            int d = direction[cx][cy];
            while (d != -1) {
                path += dir[d];
                cx -= dx[d];
                cy -= dy[d];
                d = direction[cx][cy];
            }
            reverse(path.begin(), path.end());
            cout << path.length() << "\n" << path << "\n";
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (grid[nx][ny] != '.')
                continue;

            grid[nx][ny] = grid[x][y];

            if (grid[nx][ny] == 'A')
                direction[nx][ny] = i;

            q.push({nx, ny});
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
