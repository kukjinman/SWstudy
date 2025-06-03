#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> visited;
int map_cnt = 0;
int ans = 0;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

void printer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}


int bfs(int y, int x) {

    int cur_area = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = 1;
    cur_area++;

    while(!q.empty()){
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx] == 1 || map[ny][nx] == 0) continue;

            visited[ny][nx] = 1;
            cur_area++;
            q.push(make_pair(ny, nx));  
        }


    }

    return cur_area;

}




int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                int cur = bfs(i, j);
                map_cnt++;
                ans = max(ans, cur);

            }
        }
    }

    cout << map_cnt << "\n";
    cout << ans << "\n";

    return 0;
}