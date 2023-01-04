#include <iostream>
#include <queue>

using namespace std;

#define max 1001

int n = 0;
int m = 0;
int map[max][max];

int dx[3] = { -1, 0, 1 };
int dy[3] = { 1, 1, 1 };

queue<pair<int, int>> q;

long long ans = 0;

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
}

void bfs(int x, int y)
{
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 3; i++) {

            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (ny == n) {
                // n으로 도착한 것으로 간주

                ans += (ans + 1) % 1000000007;

                break;
            }

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if (map[ny][nx] != 1)
                continue;

            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    input();

    for (int i = 0; i < m; i++) {

        if (map[0][i] == 1) {
            bfs(i, 0);
        }
    }

    cout << ans << endl;

    return 0;
}