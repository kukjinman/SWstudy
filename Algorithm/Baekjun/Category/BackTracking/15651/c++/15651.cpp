#include <iostream>

using namespace std;

int n, m;

int arr[9];

void recurse(int cnt)
{
    if (cnt == m) {

        for (int j = 0; j < m; j++) {
            cout << arr[j] << " ";
        }

        cout << '\n';

        return;
    }

    for (int i = 0; i < n; i++) {

        arr[cnt] = i + 1;
        recurse(cnt + 1);
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

    solve();

    return 0;
}