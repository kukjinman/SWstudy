#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

int row, col;

int arr[101][101];
int visited[101][101];
int leftCheezeCounter = 0;

void input()
{
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            cin >> arr[i][j];
        }
    }
}

void printer()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            cout << arr[i][j];
        }
        cout << endl;
    }
}

queue<pair<int, int>> q;
void bfs(int x, int y)
{
    q.push(make_pair(x, y));

    while (!q.empty()) {

        int cur_x = q.front().first;
        int cur_y = q.front().second;
        visited[cur_x][cur_y] = 1;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx < 0 || nx > row || ny < 0 || ny > col)
                continue;
            if (visited[nx][ny] == 1)
                continue;
            if (arr[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                continue;
            }
            // arr[nx][ny] is 1 in below code.
            visited[nx][ny] = 1;
            arr[nx][ny] = 0;
        }
    }
}

int cheezeChecker()
{

    int ret = 0;
    int cnt = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (arr[i][j] == 1)
                cnt++;
        }
    }

    if (cnt >= 1) {
        // cout << "cnt : " << cnt << endl;
        ret = cnt;
    } else {
        // cout << "[0]cnt : " << cnt << endl;
    }
    //ret ture : there is cheeze
    //ret false : there is no cheeze

    leftCheezeCounter = ret;

    return ret;
}

void solve(int& run_cnt_, int& last_cheeze_cnt_)
{

    int noCheezeFlag = false;

    /*    
4 6
0 0 0 0 0 0
0 0 0 1 1 0
0 1 1 1 1 0
0 0 0 0 0 0
output: 1 0
correct answer: 1 6
*/
    //Initializing last_cheeze_cnt_ for the above case.
    if (cheezeChecker() >= 1) {
        // cout << "there is still cheeze" << endl;
        last_cheeze_cnt_ = leftCheezeCounter;
    }

    while (!noCheezeFlag) {

        memset(visited, 0, sizeof(visited));

        // cout << "-------------------" << endl;
        // printer();

        bfs(0, 0);
        run_cnt_++;

        // cout << "-------------------" << endl;
        // printer();

        if (cheezeChecker() >= 1) {
            // cout << "there is still cheeze" << endl;
            last_cheeze_cnt_ = leftCheezeCounter;
        } else {
            // cout << "there is no cheeze" << endl;
            noCheezeFlag = true;
        }
    }
}

int main()
{
    input();
    // printer();

    int run_cnt = 0;
    int last_cheeze_cnt = 0;

    solve(run_cnt, last_cheeze_cnt);

    cout << run_cnt << endl;
    cout << last_cheeze_cnt << endl;
}