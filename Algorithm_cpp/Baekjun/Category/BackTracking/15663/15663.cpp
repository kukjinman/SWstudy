#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> arr;
vector<int> result;
vector<bool> visited;

void dfs(int dep)
{
    if (dep == m) {
        for (int i = 0; i < m; i++){
            cout << result[i] << " ";        
        }
        cout << "\n";
        return;
    }
    int tmp = -1;
    for (int i = 0; i < n; i++){

        if (!visited[i] && arr[i] != tmp){
            visited[i] = true;
            
            result[dep] = arr[i];
            tmp = arr[i]; 
            dfs(dep + 1);
            visited[i] = false;
        }

    }


}


int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;

    arr.resize(n);
    result.resize(m);
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    // for (int i=0; i < n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    dfs(0);

    return 0;
}


