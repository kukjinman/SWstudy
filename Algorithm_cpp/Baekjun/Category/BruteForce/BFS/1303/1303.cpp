#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<char>> map;
vector<vector<int>> visited;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int bfs(int y, int x, char color) {
    int count = 1;
    queue<pair<int, int>> q;
    q.push({y,x});
    visited[y][x] = 1;

    while(!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){

            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if( ny <0 || ny >= n || nx < 0 || nx >= m ) continue; // 범위 체크
            if( visited[ny][nx] == 1 ) continue; // 방문 체크

            if(map[ny][nx] == color) { // 같은 색깔인 경우
                visited[ny][nx] = 1;
                q.push({ny, nx});
                count++;
            } 

        }

    }
    return count;

}

int count_w = 0;
int count_b = 0;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // 가로 세로 주의!!!
    cin >> m >> n;
    map.resize(n, vector<char>(m));
    visited.resize(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == 0) {
            
                if(map[i][j] == 'W'){
                    
                    int w_tmp = bfs(i, j, 'W');
                    count_w += (w_tmp * w_tmp);
                    // cout << "White Count: " << w_tmp << endl;

                }else if(map[i][j] == 'B'){
                    int b_tmp = bfs(i, j, 'B');
                    count_b += (b_tmp * b_tmp);
                    // cout << "Black Count: " << b_tmp << endl;
                }

            }
        }
    }


    cout << count_w << " " << count_b << endl;

    
    return 0;
}