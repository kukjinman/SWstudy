#include <cmath>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

bool visited[1001][1001];

int dy[3] = { 0, 1, 1 };
int dx[3] = { 1, 0, 1 };

int isSquare(int cur, int y_, int x_, vector<vector<int>> map)
{
    queue<pair<int, int>> q;
    q.push(make_pair(y_, x_));
    visited[y_][x_] = true;

    int ret = 1;
    // x의 값이 1씩 증가할때마다 while return이 없으면 ret도 증가하도록

    // cout << "cur : " << cur << " y_ : " << y_ << " x_ : " << x_ << endl;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 3; i++) {

            int ny = y + dy[i];
            int nx = x + dx[i];

            int ret = max(abs(nx - x_), abs(ny - y_));
            if (ny >= map.size() || ny < 0 || nx >= map.size() || nx < 0)
                continue;

            if (visited[ny][nx] == true)
                continue;

            if (map[ny][nx] != cur) {
                // cout << "[out] cur : " << cur << " ny : " << ny << " nx : " << nx << endl;
                // cout << "[out] ret : " << ret << endl;

                return ret;
            }
            // cout << " ret : " << ret << endl;

            visited[ny][nx] = true;
            q.push(make_pair(ny, nx));
        }
    }
    // cout << " ret : " << ret << endl;

    return ret + 1;
}

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    memset(visited, 0, sizeof(visited));

    int max = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {

            if (board[i][j] == 0)
                continue;

            int tmp;
            tmp = isSquare(board[i][j], i, j, board);
            memset(visited, 0, sizeof(visited));

            if (max < tmp) {
                max = tmp;
                cout << " max : " << max << endl;
            }
        }
        cout << endl;
    }

    answer = max * max;

    return answer;
}