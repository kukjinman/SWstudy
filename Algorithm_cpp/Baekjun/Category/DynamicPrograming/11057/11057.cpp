#include <iostream>
#include <vector>

using namespace std;


//오르막 수가 자리수가 증가할때
//전 자리수까지의 경우의 수는 동일하다
//그러므로 DP를 사용해야 한다고 생각하면되고
//점화식은 수를 나열해서 반복되는 부분을 보아야 한다.


int n;
int dp[1001][1001];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    int ans = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;



        }

    }

    for (int i = 0; i < 10; i++)
    {

        ans = (ans + dp[n][i]) % 10007;

    }

    ans = ans % 10007;

    cout << ans << endl;

    return 0;
}
