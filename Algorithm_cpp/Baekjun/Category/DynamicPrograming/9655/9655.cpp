#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[1001];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    dp[0] = dp[1] = dp[3] = 1;
    dp[2] = 0;

    for (int i = 4; i <= n; i++)
    {
        // cout << " dp i -1 : "<< dp[i-1] << " i-3 : " << dp[i-3] << " i-4 : " << dp[i-4] << endl;

        if ((dp[i - 1] == 0) || (dp[i - 3] == 0))
        {

            dp[i] = 1;
        }
        else
        {
            dp[i] = 0;
        }


    }

    if (dp[n])
    {
        cout << "SK" << endl;
    }
    else
    {
        cout << "CY" << endl;
    }


    return 0;
}
