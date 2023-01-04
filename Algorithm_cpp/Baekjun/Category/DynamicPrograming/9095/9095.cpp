#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[12];


/*
�� n ��°���� 1,2,3�� ������ �̷���� ����
n-1 ��°���� ������ ���� 1�� ���ϴ� ���
n-2 ��°���� ������ ���� 2�� ���ϴ� ���
n-3 ��°���� ������ ���� 3�� ���ϴ� ���� ��Ÿ�� �� �ִ�.
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
