#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int r1, c1, r2, c2;

vector<vector<int>> map;
vector<vector<int>> visited;
int dx[6] = { -2, -2, 0 , 0 , 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };


int ans = 0;

void print_map() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void bfs(int x, int y) {

    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    visited[y][x] = 1;

    while(!q.empty()) {

        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++){

            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue; // 범위 체크
            if (visited[ny][nx] == 1) continue; // 방문 체크

            visited[ny][nx] = 1; // 방문 처리
            map[ny][nx] = map[cur_y][cur_x] + 1; // 현재 위치에서 이동한 위치의 거리를 기록
            q.push(make_pair(nx, ny)); // 큐에 추가
            // cout << "Current Position: (" << cur_y << ", " << cur_x << ") -> Move to (" << ny << ", " << nx << ") with distance: " << map[ny][nx] << endl;
        }
        // print_map();

    }





}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    map.resize(n, vector<int>(n, 0));
    visited.resize(n, vector<int>(n, 0));
    bfs(r1, c1);

    if (map[c2][r2] == 0) {
        cout << -1 << endl; // 도달할 수 없는 경우
        return 0;
    }
    cout << map[c2][r2] << endl; // 목표 위치까지의 최소 이동 횟수 출력
    return 0;
}