#include <iostream>
#include <vector>

using namespace std;


//������ ���� �ڸ����� �����Ҷ�
//�� �ڸ��������� ����� ���� �����ϴ�
//�׷��Ƿ� DP�� ����ؾ� �Ѵٰ� �����ϸ�ǰ�
//��ȭ���� ���� �����ؼ� �ݺ��Ǵ� �κ��� ���ƾ� �Ѵ�.


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
