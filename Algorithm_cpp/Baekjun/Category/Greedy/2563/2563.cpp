#include <iostream>
#include <vector>

using namespace std;


int n;

vector<pair<int,int>> paper;
vector<vector<int>> map;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    map.resize(101, vector<int>(101, 0));   
    paper.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> paper[i].first >> paper[i].second;
    }

    for (int i = 0; i < n; i++) {
        int x = paper[i].first;
        int y = paper[i].second;

        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                map[j][k] = 1; // 종이 영역을 1로 표시
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (map[i][j] == 1) {
                ans++;
            }
        }
    }

    cout << ans << "\n"; // 전체 종이 영역의 넓이를 출력
    return 0;

}