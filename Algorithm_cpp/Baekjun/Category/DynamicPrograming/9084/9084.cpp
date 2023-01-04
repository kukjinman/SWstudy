#include <algorithm>
#include <iostream>
using namespace std;

int T, n;
int target;
int coin[21];

void input()
{
    cin >> T;

    for (int i = 0; i < T; i++) {
        n = 0;
        memset(coin, 0, sizeof(coin));
        target = 0;

        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> coin[j];
        }

        cin >> target;

        solve();
    }
}

void solve()
{
    int cnt = n;

}

int main(int argc, char* argv[])
{
    input();

    return 0;
}