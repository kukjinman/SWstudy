#include <iostream>
#include <queue>

using namespace std;

char map[51][51];
int n = 0;
int m = 0;

queue<pair<pair<int, int>, pair<int, int>>> q;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

// whenever key is updated, visited is renewed
bool visited[51][51][1 << 6];

void input()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++) {

        string tmp;
        cin >> tmp;

        for (int j = 0; j < m; j++) {

            map[i][j] = tmp[j];
        }
    }

    // for (int i = 0; i < y; i++) {

    //     for (int j = 0; j < x; j++) {
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }
}

pair<int, int> finding_starting_point()
{

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            if (map[i][j] == '0') {
                map[i][j] = '.';
                return make_pair(j, i);
            }
        }
        // cout << endl;
    }

    return make_pair(-1, -1);
}

bool having_key(int key_, int door_)
{

    // cout << "key_ : " << key_ << endl;
    // cout << "door_ : " << (1 << door_) << endl;

    if (key_ & (1 << door_)) {
        return true;
    }

    return false;
}

int dfs(pair<int, int> start_)
{
    q.push(make_pair(start_, make_pair(0, 0)));
    visited[start_.first][start_.second][0];

    while (!q.empty()) {

        int x = q.front().first.first;
        int y = q.front().first.second;

        // sum and key is updated by each queue.
        // Each queue has different key and sum so it shall be checekd every queue.
        // This can be re-desinged by recursive function
        int sum = q.front().second.first;
        int key = q.front().second.second;

        q.pop();

        if (map[y][x] == '1')
            return sum;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            // cout << " map : " << map[ny][nx] << " ny : " << ny << " nx : " << nx << " key : " << key << endl;

            if (visited[ny][nx][key]) {

                continue;
            }

            if (map[ny][nx] == '#') {
                continue;
            } else if (map[ny][nx] == '.') {
                visited[ny][nx][key] = true;
                q.push(make_pair(make_pair(nx, ny), make_pair(sum + 1, key)));
            } else if (map[ny][nx] == '1') {
                visited[ny][nx][key] = true;
                q.push(make_pair(make_pair(nx, ny), make_pair(sum + 1, key)));
            } else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'f') {
                // cout << "found key : " << map[ny][nx] << endl;

                int tmp_key = key | (1 << (map[ny][nx] - 'a'));

                //next queue will start new tmp_key visited check
                //This is independant with the previous key route
                visited[ny][nx][tmp_key] = true;
                // cout << "tmp_key : " << tmp_key << endl;

                q.push(make_pair(make_pair(nx, ny), make_pair(sum + 1, tmp_key)));

            } else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'F') {
                // cout << " door : " << map[ny][nx] << endl;
                visited[ny][nx][key] = true;

                if (having_key(key, map[ny][nx] - 'A')) {

                    // cout << " door opened : " << map[ny][nx] << endl;

                    q.push(make_pair(make_pair(nx, ny), make_pair(sum + 1, key)));
                }
            }
        }
    }

    return -1;
}

void solve()
{
    pair<int, int> start;
    start = finding_starting_point();

    // cout << " first " << start.first << " second : " << start.second << endl;

    cout << dfs(start) << endl;
}

int main()
{
    input();
    solve();

    return 0;
}