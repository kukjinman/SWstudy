#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map;

int max_area = 0;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;
    map.resize(n+1, vector<int>(m+1));

    for (int i =1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            map[i][j] = (c == '1') ? 1 : 0; // Convert input to 1 or 0

        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (map[i][j] == 1) {
                

                map[i][j] = min(map[i-1][j], min(map[i][j-1], map[i-1][j-1])) + 1;
                max_area = max(max_area, map[i][j]);
                
            }
        }
    }

    cout << max_area * max_area << endl; // Output the area of the largest square
    
    return 0;
}