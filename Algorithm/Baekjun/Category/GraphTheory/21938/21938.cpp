#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

vector<vector<int>> map;

vector<vector<int>> visited;

int n = 0, m = 0;
int t = 0;

int cnt = 0;

void input()
{

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int r = 0, g = 0, b = 0;
            cin >> r >> g >> b;

            map[i][j] = (r + g + b) / 3;
        }
    }

    cin >> t;
}

void bfs(int x_, int y_)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x_, y_));
    visited[x_][y_] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny] == 1)
                continue;
            if (map[nx][ny] == 0)
                continue;

            map[nx][ny] = cnt;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = 1;
        }
    }
}

void solve()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (map[i][j] >= t) {
                map[i][j] = 255;
            }
            else {
                map[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (visited[i][j] != 1 && map[i][j] == 255) {

                cnt++;
                // cout << " cnt : " << cnt << endl;
                bfs(i, j);
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {

    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

int main()
{
    cin >> n >> m;

    map.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<int>(m, 0));

    input();

    solve();

    cout << cnt << endl;
}