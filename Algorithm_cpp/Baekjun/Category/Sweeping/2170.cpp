#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int n = 0;
vector<pair<int, int>> v;
const int INF = 1e9 + 1;

const int neg_int = -2147483648;
int main()
{
    cin >> n;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < n; i++) {
        int f = 0;
        int s = 0;

        cin >> f >> s;

        v.push_back(make_pair(f, s));
    }

    sort(v.begin(), v.end());

    // for (int i = 0; i < v.size(); i++) {
    //     cout << " f :  " << v[i].first << " s : " << v[i].second << endl;
    // }

    int ans = 0;

    // INT MIN을 사용하지 않으면 - 범위의 숫자들이 0과 비교되어 무시됨.
    int left = neg_int;
    int right = neg_int;

    for (int i = 0; i < v.size(); i++) {

        if (v[i].first < right) {
            right = max(right, v[i].second);
        } else {
            ans += right - left;

            right = v[i].second;
            left = v[i].first;
        }
    }

    ans += right - left;

    cout << ans << endl;

    return 0;
}