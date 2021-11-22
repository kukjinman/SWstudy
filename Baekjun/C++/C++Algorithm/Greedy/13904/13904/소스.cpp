
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    int deadline;
    int score;
    int end;
    int result = 0;
    int arr[1001];
    vector<pair<int, int>> v;

    memset(arr, 0, sizeof(arr));

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> deadline >> score;
        v.push_back({ score, deadline });
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());

    for (int j = 0; j < n; j++) {

        // cout << "d : " << v.back().first << " w : " << v.back().second << endl;
        v.pop_back();
    }

    for (int i = 0; i < n; ++i) {
        end = v[i].second;
        while (end >= 1) {
            if (arr[end] == 0) {
                arr[end] = v[i].first;

                // cout << " end : " << end << " arr[end] : " << arr[end] << endl;
                break;
            } else {
                // cout << "[##] end : " << end << " arr[end] : " << arr[end] << endl;

                --end;
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        result += arr[i];
    }

    cout << result << endl;

    return 0;
}