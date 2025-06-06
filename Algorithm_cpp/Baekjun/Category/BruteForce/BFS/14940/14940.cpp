#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int s_y, s_x; // 시작점의 좌표

vector<vector<int>> graph;
vector<vector<int>> dist;
vector<vector<int>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct point{
    int y, x;
    int dist_num;
};


void bfs(int start_y, int start_x) {
    queue<point> q;
    point tmp = {start_y, start_x, 0};
    q.push(tmp);
    visited[start_y][start_x] = 1;
    dist[start_y][start_x] = 0; // 시작점의 거리는 0

    while(!q.empty()){

        int cur_y = q.front().y;
        int cur_x = q.front().x;
        int cur_dist = q.front().dist_num;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if(ny <0 || ny >= n || nx <0 || nx >= m) continue;
            if(visited[ny][nx] == 1) continue;
            if(graph[ny][nx] == 0) continue;

            visited[ny][nx] = 1;
            dist[ny][nx] = cur_dist + 1; // 다음 위치의 거리는 현재 위치의 거리 + 1
            point next = {ny, nx, cur_dist + 1};
            q.push(next);

        }
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    graph.resize(n, vector<int>(m));
    dist.resize(n, vector<int>(m, -1));
    visited.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) {
                dist[i][j] = 0; // 시작점은 거리 0
            }
            else if(graph[i][j] == 2) {
                s_y = i; // 시작점의 y좌표
                s_x = j; // 시작점의 x좌표
            }
        }
    }

    bfs(s_y, s_x);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cout << dist[i][j] << " ";
        }

        cout << "\n";

    }
}