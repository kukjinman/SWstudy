#include <iostream>

using namespace std;

int n;

int arr[1001];

int cur = 0;

int ans = 0;

void recursion(int cnt, int rec_max)
{
    if (cnt == n) {
        if (ans < rec_max) {
            ans = rec_max;
        }

        return;
    }

    int cnt_add = 0;
    int buf = 0;
    for (int i = cnt; i < n; i++) {

        if (arr[i] < cur) {
            cnt_add++;
            continue;
        }

        buf = cur;
        cur = arr[i];
        cout << " cur : " << cur << " rec_max : " << rec_max << endl;

        recursion(cnt + cnt_add + 1, rec_max + 1);
        cur = buf;
    }
}

void solve()
{

    recursion(0, 0);

    cout << ans << endl;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> arr[i];
    }

    solve();

    return 0;
}