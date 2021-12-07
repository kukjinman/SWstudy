#include <algorithm>
#include <iostream>
using namespace std;

int n;
int arr[200];

void input()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve()
{

    int dp[200];
    int res = 0;

    for (int i = 0; i < n; i++) {

        dp[i] = 1;
        for (int j = 0; j < i; j++) {

            if (arr[i] > arr[j] && dp[i] <= dp[j]) {
                dp[i] += 1;
            }
        }

        res = max(res, dp[i]);
    }

    cout << n - res << endl;
}

int main(int argc, char* argv[])
{
    input();
    solve();

    return 0;
}