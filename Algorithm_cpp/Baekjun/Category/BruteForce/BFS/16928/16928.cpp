#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<int> ladder(101); // 사다리 정보
vector<int> snake(101); // 뱀 정보
vector<int> visited(101, 0); // 방문 여부
int ans = 0; // 최소 이동 횟수

void bfs(int start) {
    queue<pair<int,int>> q;
    int cnt = 0;
    q.push({start, cnt});
    visited[start] = 1;

    while(!q.empty()){
        int cur = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();


        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if( ladder[next] != 0){
                next = ladder[next]; // 사다리 이동
            } else if (snake[next] != 0) {
                next = snake[next]; // 뱀 이동
            }

            if (next > 100) continue;
            if (visited[next] == 1) continue; // 이미 방문한 경우

            if (next == 100) { // 도착 지점에 도달한 경우
                // cout << "[F]Current Position: " << cur << " -> Move to " << next << " with count: " << cur_cnt + 1 << endl;
                cout << cur_cnt + 1<< "\n";
                return;
            }

            visited[next] = 1;
            q.push({next,cur_cnt+ 1}); // 다음 위치를 큐에 추가
            
            // cout << "Current Position: " << cur << " -> Move to " << next << " with count: " << cur_cnt + 1 << endl;

        }



    }

}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ladder[a] = b;
    }

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        snake[a] = b;
    }

    bfs(1);





}