// #include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int result = 0;

//input arr
int arr[8][8];
//arr buff to check virus spread map.
// cannot overwrite arr so this is needed for add_wall.
int arr_copy[8][8];
vector<pair<int, int>> v;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void print_map(const int arr_[8][8], const int n, const int m)
{

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            cout << arr_[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----------------------------------------" << endl;
}

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < v.size(); i++) {
        q.push(make_pair(v[i].first, v[i].second));
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            } else {
                if (arr_copy[nx][ny] == 0) {
                    arr_copy[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    // print_map(arr_copy, N, M);

    //checking the max result

    int cur_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (arr_copy[i][j] == 0) {
                cur_cnt++;
            }
        }
    }

    if (result < cur_cnt) {
        result = cur_cnt;
    }
}

void add_wall(int cnt)
{
    if (cnt == 3) {
        // all walls are added
        // copy(arr, arr + 64, arr_copy);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                arr_copy[i][j] = arr[i][j];
            }
        }

        bfs();

        return;
    }

    // recurse till cnt becomes 3
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                add_wall(cnt + 1);
                arr[i][j] = 0;
            }
        }
    }
}

void solve()
{
    // i - 0 ~ N   j - 0 ~ M
    // Trying all 0 block to add wall
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                add_wall(1);
                arr[i][j] = 0;
            }
        }
    }

    cout << result << endl;
}

int main(int argc, char* argv[])
{

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                v.push_back(make_pair(i, j));
            }
        }
    }

    solve();

    return 0;
}