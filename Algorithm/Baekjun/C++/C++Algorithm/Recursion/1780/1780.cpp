#include <iostream>

using namespace std;

int n;

int map[2187][2187];

void recurse(int cnt)
{

}

void solve()
{

    recurse(0);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            cin >> map[i][j];
        }
    }

    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {

    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }

    solve();

    return 0;
}