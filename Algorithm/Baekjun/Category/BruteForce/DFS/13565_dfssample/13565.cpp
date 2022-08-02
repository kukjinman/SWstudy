#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

vector<vector<int>> map;

// vector<vector<int>> visited;

int n = 0, m = 0;

bool SuccessFlag = false;

void dfs(int x, int y)
{

    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx == n) {
            // cout << " Goal !! " << nx << " " << ny << endl;
            SuccessFlag = true;
        }

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
            continue;
        }

        // if (visited[nx][ny])
        //     continue;

        if (map[nx][ny] != 0)
            continue;

        map[nx][ny] = 2;
        // visited[nx][ny] = true;
        dfs(nx, ny);
        // visited[nx][ny] = false;
    }
}

void solve()
{

    for (int i = 0; i < m; i++) {

        if (map[0][i] == 0)
            dfs(0, i);

        // cout << " ---------- " << endl;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {

        //         cout << map[i][j];
        //     }
        //     cout << endl;
        // }

        if (SuccessFlag == true)
            return;
    }
}

int main()
{
    cin >> n >> m;

    map.resize(n, vector<int>(m, 0));
    // visited.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            scanf("%1d", &map[i][j]);
        }
    }

    solve();

    if (SuccessFlag == true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    // cout << " ---------- " << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {

    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }
}