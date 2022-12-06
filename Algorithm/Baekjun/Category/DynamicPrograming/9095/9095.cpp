#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[12];


/*
즉 n 번째에서 1,2,3의 합으로 이루어진 경우는
n-1 번째에서 각각의 값에 1을 더하는 경우
n-2 번째에서 각각의 값에 2를 더하는 경우
n-3 번째에서 각각의 값에 3을 더하는 경우로 나타낼 수 있다.
*/


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 12; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        cout << dp[tmp] << endl;
    }


    return 0;
}
