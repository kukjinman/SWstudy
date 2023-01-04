#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { 1, 0, 0, -1 };

#define MAX 21

int n;
int arr[MAX][MAX];
int dist[MAX][MAX];

int ans = 0;

queue<pair<int, int>> q;

bool prey_check(int& x, int& y, int& shark_size, int& feed)
{

    memset(dist, -1, sizeof(dist));
    q.push(make_pair(x, y));
    dist[y][x] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (ny >= n || ny < 0 || nx >= n || nx < 0) {
                continue;
            }

            if (arr[ny][nx] > shark_size)
                continue;
            else {
                if (dist[ny][nx] == -1) {
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int my = 21;
    int mx = 21;
    int m_dist = 401;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            cout << dist[i][j] << " ";

            if (arr[i][j] != 0 && arr[i][j] != 9 && arr[i][j] < shark_size && dist[i][j] != -1 && dist[i][j] <= m_dist) {

                m_dist = dist[i][j];
                my = i;
                mx = j;
            }
        }
        cout << endl;
    }

    if (m_dist == 401)
        return false;
    else {
        arr[y][x] = 0;
        y = my;
        x = mx;

        feed += arr[y][x];
        if (shark_size <= feed) {
            feed = feed - shark_size;
            shark_size++;
        }

        cout << "size : " << shark_size << " feed : " << feed << endl;
        arr[my][mx] = 9;
        ans += m_dist;
        cout << "--------------------------------------" << endl;
        cout << ans << endl;
        cout << "--------------------------------------" << endl;
        return true;
    }
}

void solve(int& x, int& y)
{

    int shark_size = 2;
    int feed = 0;
    while (1) {

        if (prey_check(x, y, shark_size, feed)) {

            continue;
        } else {
            break;
        }
    }

    cout << ans << endl;
}

int main()
{
    int s_x = 0;
    int s_y = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 9) {
                s_x = j;
                s_y = i;
            }
        }
    }

    solve(s_x, s_y);
}
