#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;

vector<int> ans;
vector<int> visited;
vector<int> graph[100001]; // 최대 노드 수 100000

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    ans.resize(n+1,0);
    visited.resize(n+1, 0);
    visited[1] = 1; // 루트 노드 방문 처리
    
    
    for (int i = 0; i < n -1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1); // 루트 노드부터 시작
    visited[1] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (!visited[next]) { // 방문하지 않은 노드만 처리
                visited[next] = 1; // 방문 처리
                ans[next] = cur; // 부모 노드 기록
                q.push(next); // 큐에 추가
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << ans[i] << "\n"; // 각 노드의 부모 노드 출력
    }




    return 0;
}

