#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int n, m;

int arr[9];

bool visited[9];

int ans[9];

void recurse(int cnt)
{

    // cout << " cnt : " << cnt << endl;

    if (cnt == m) {

        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

        // exit
        return;
    }

    for (int i = 0; i < n; i++) {

        if (visited[i] == true)
            continue;

        visited[i] = true;
        ans[cnt] = arr[i];
        recurse(cnt + 1);
        visited[i] = false;
    }
}

void solve()
{

    recurse(0);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    // for (int i = 0; i < n; i++) {

    //     cout << " " << arr[i];
    // }
    // cout << endl;

    solve();

    return 0;
}