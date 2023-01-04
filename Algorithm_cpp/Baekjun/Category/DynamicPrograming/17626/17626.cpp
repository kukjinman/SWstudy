#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[50001];
/*

N���� 10�϶�
Sqrt(10) = 3.16227766016838 �� ������
3����
2����
1����

�������� ���ָ鼭 �ּ� ������ update���ش�.

�ڵ������� ����
N���� 100�϶�
dp[1] ~ dp[100] ���� ��� ������Ʈ�ϴ� for loop�� ������

������ dp[n]�� dp[a] + dp[b]�� �� ǥ���� �����ϸ�,
�ִ��� �����δ� 1^2 + 1^2 + 1^2 ... �� ���� ���� ǥ���� ����������
min���� �׻� �ּҰ��� update�Ͽ� dp[n]���� �־��ش�.

2��° for loop������
�̹����� �ٽ��� ������ ������ ǥ���ǹǷ�
2�������� sqrt(n)���� ���ո����� Big(O) �� �ٿ��ش�.


*/


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp[1] = 1;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[1] + dp[i - 1];
		for (int j = 2; j * j <= i; j++)
		{
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}

	cout << dp[n];
}