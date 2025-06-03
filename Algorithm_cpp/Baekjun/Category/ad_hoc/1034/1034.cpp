#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int n, m;
int ans = 0;
string s[51];
map<string, int> check_map;


// 이 문제의 핵심은 
//  k번동안 스위치를 모두 써야 한다는 점
// k번의 스위치 사용으로 모든 행을 1로 만들 수 있는지 확인하는 것
// 1로 만드는 행만이 유요한 행이됨으로 그 외의 조건은 continue로 버려버리는 것
// 1로 만들 수 있는 행들만 map에 저장하여 마지막에 최대치 구하기

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int k = 0;
    cin >> k;

    for (int i = 0; i < n; i++) {

        int zero_count = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '0') {
                zero_count++;
            }
        }

        if (zero_count > k) {
            continue; // If the number of zeros exceeds k, skip this row
        }

        if (zero_count % 2 != k % 2) {
            continue; // If the parity of zeros does not match k, skip this row
        }

        if (check_map.find(s[i]) == check_map.end()) {
            check_map[s[i]] = 1; // Store the row in the map if it is valid
        } else {
            check_map[s[i]]++; // Increment the count if the row already exists
        }

    }

    for (const auto& entry : check_map) {
        ans = max(ans, entry.second); // Find the maximum count of valid rows
    }
    cout << ans << endl; // Output the maximum count of valid rows

    return 0;
}