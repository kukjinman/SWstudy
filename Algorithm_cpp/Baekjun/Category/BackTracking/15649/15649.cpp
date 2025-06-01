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


int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;

    result.resize(m);
    visited.resize(n + 1, false);

    dfs(0);

    return 0;
}