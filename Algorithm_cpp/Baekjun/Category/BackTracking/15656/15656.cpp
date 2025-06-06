#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> result;
vector<int> arr;

void dfs(int dep){

    if(dep == m) {

        for(auto i : result) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++){

        result.push_back(arr[i]);
        dfs(dep + 1);
        result.pop_back(); // 백트래킹을 위해 마지막 요소 제거

    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;


    for (int i = 0; i < n; i++){

        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    dfs(0);


    return 0;
}