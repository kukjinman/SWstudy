#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int T;
set<int> team;

int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dx[8] = {0, 0, 1, -1, 1, -1, -1, 1};

void bfs(int sy, int sx, vector<vector<int>>& graph, vector<vector<int>>& visited){

    for (auto it : team) {
        if (it == graph[sy][sx]) 
            return; // 이미 같은 팀이 발견되었으면 종료
    }

    queue<pair<int,int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;

    while(!q.empty()){

        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){

            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if (ny < 0 || ny >= graph.size() || nx < 0 || nx >= graph[0].size()) continue;
            if (visited[ny][nx] == 1) continue;
            if (graph[ny][nx] == -1) continue;

            if(graph[ny][nx] == graph[sy][sx]){
                visited[ny][nx] = 1;
                team.insert(graph[ny][nx]);

            }

        }
        

    }


}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int i = 0; i < T;i++)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        graph.resize(n, vector<int>(m, 0));

        for (int j = 0; j <n;j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> graph[j][k];
            }
        }

        
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (graph[j][k] != -1) {

                    if (visited[j][k] == 0){
                        bfs(j, k, graph, visited);
                    }
                }
            }
        }


        cout << team.size() << "\n";
        team.clear(); // 다음 테스트 케이스를 위해 팀 초기화
    }


}