
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    int pos;
    int result = 0;

    //arr[deadline] 부터 arr[deadline - 값의 개수]까지 계속 update할 pallet
    int arr[1001];

    // score의 오름차순 정렬 및 value 보관용
    vector<pair<int, int>> v;

    memset(arr, 0, sizeof(arr));

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int deadline;
        int score;

        cin >> deadline >> score;
        v.push_back({ score, deadline });
    }

    //score에 대하여 내림차순으로 정렬
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    // for (int j = 0; j < n; j++) {

    //     cout << "score : " << v[j].first << " deadline : " << v[j].second << endl;
    //     // v.pop_back();
    // }

    for (int i = 0; i < v.size(); ++i) {
        pos = v[i].second;

        //
        while (pos >= 1) {

            // 이미 값이 0이 아니면 이전에 내림차순으로 더 큰 값이 저장되어 있음.
            // 현재 값을 무시해도 됨.
            if (arr[pos] == 0) {
                arr[pos] = v[i].first;

                // cout << " pos : " << pos << " arr[pos] : " << arr[pos] << endl;
                break;
            } else {
                // cout << "[##] pos : " << pos << " arr[pos] : " << arr[pos] << endl;

                // 이후의 vector 값을 위해 남는 arr에 저장해 둠
                --pos;
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        result += arr[i];
    }

    cout << result << endl;

    return 0;
}