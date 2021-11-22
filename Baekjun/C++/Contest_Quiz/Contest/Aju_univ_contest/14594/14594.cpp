#include <cstring>
#include <deque>
#include <iostream>

using namespace std;

#define Max 10000

deque<pair<int, int>> dq;

int arr[Max];

int main(int argc, char** argv)
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    int N = 0;
    int M = 0;
    cin >> N >> M;

    memset(arr, -1, sizeof(arr));

    for (int i = 0; i < M; i++) {
        int first = 0;
        int second = 0;

        cin >> first >> second;
        dq.push_back(make_pair(first, second));
    }

    int cnt = 0;
    int prev_end = -99;

    while (!dq.empty()) {

        int s = dq.front().first - 1;
        int e = dq.front().second - 1;

        if (dq.size() == M) {
            prev_end = e;
        } else {

            if (prev_end < s)
                cnt++;
        }

        dq.pop_front();

        for (int i = s; i <= e; i++) {
            arr[i] = cnt;
        }
        prev_end = e;
    }

    int ans = 0;
    int temp = -99;
    for (int i = 0; i < N; i++) {

        // cout << " i : " << i << " arr[i] : " << arr[i] << endl;
        if (arr[i] == -1)
            ans++;
        else if (arr[i] != -1) {

            if (arr[i] != temp) {
                temp = arr[i];
                ans++;
            } else
                continue;
        }
    }

    cout << ans << endl;

    return 0;
}
