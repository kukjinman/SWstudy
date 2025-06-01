#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> result;
vector<int> visited;

void dfs(int dep){

    if (dep == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            result[dep] = i;
            dfs(dep + 1);
            visited[i] = false;
        }
    }


}