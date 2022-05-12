#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(int y, int x, int y_max, int x_max, int cur_val, vector<vector<int>> map, int& g_max_, bool visited_[][101])
{
    int cur_max = 0;
    int dy[4] = { 0, 0, -1, 1 };
    int dx[4] = { -1, 1, 0, 0 };

    queue<pair<int, int>> q;

    q.push(make_pair(y, x));

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= y_max || ny < 0 || nx >= x_max || nx < 0)
                continue;

            if (visited_[ny][nx])
                continue;

            if (map[ny][nx] != cur_val)
                continue;

            cur_max++;
            visited_[ny][nx] = true;
            q.push(make_pair(ny, nx));
        }
    }

    if (g_max_ < cur_max)
        g_max_ = cur_max;

    // cout << cur_max << " cur val : " << cur_val << endl;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    //init
    int g_max = 0;
    bool visited[101][101];

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (picture[i][j] == 0 || visited[i][j])
                continue;
            else {
                dfs(i, j, m, n, picture[i][j], picture, g_max, visited);
                number_of_area++;
            }
        }
    }

    max_size_of_one_area = g_max;

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}