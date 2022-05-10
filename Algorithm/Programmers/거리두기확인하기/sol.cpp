#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

bool dfs(int y_, int x_, vector<string> map_)
{

    queue<pair<pair<int, int>, int>> q;

    bool visited[6][6];
    memset(visited, 0, sizeof(visited));

    q.push(make_pair(make_pair(y_, x_), 0));
    visited[y_][x_] = true;

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int sum = q.front().second;
        q.pop();

        // cout << " y : " << y << " x : " << x << " sum : " << sum << endl;
        if (sum >= 2) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 5 || ny < 0 || nx >= 5 || nx < 0)
                continue;

            if (visited[ny][nx])
                continue;

            if (map_[ny][nx] == 'X')
                continue;

            if (map_[ny][nx] == 'P') {
                // cout << "P found ny : " << ny << " nx : " << nx << endl;
                return false;
            }

            visited[ny][nx] = true;
            q.push(make_pair(make_pair(ny, nx), sum + 1));
        }
    }

    return true;
}

int solve(vector<string> map)
{
    bool ret = true;

    // cout << " --------------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (map[i][j] == 'P') {

                ret = dfs(i, j, map);

                if (ret == false)
                    return 0;
                // cout << "ret : " << ret << " P found i : " << i << " j : " << j << endl;
            }
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (auto v : places) {

        // for (int i = 0; i < 5; i++) {
        //     for (int j = 0; j < 5; j++) {
        //         cout << v[i][j];
        //     }
        //     cout << endl;
        // }

        // <int>에다가 bool 처넣지 말 것
        // 프로그래머스에서 일부는 맞고 일부(테케 2~13, 15,16 , 18 ~ 22, 27, 30)는 틀리게 처리 함.
        answer.push_back(solve(v));
    }

    return answer;
}