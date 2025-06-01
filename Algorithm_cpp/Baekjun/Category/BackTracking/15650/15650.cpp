#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> result;
vector<bool> visited;


void dfs(int dep, int s){

    if (dep == m){

        // cout <<" size : " << result.size() << "\n";
        for (int i = 0; i < m; i++){
            cout << result[i]<< " ";
        }
        cout << "\n";

        return;
    }   
    for (int i = s; i <= n; i++){
        if(visited[i] == false){
            visited[i] = true;
            result[dep] = i;
            // cout << "Res : " << result[dep] << "\n";
            dfs(dep + 1, i + 1);
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

    dfs(0, 1);

    return 0;
}


