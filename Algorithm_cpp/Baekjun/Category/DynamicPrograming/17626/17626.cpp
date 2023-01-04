#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[50001];
/*

N값을 10일때
Sqrt(10) = 3.16227766016838 의 값에서
3제곱
2제곱
1제곱

제곱별로 뺴주면서 최소 조합을 update해준다.

코드적으로 보면
N값이 100일때
dp[1] ~ dp[100] 까지 모두 업데이트하는 for loop를 돌리고

각각의 dp[n]은 dp[a] + dp[b]로 다 표현이 가능하며,
최대의 개수로는 1^2 + 1^2 + 1^2 ... 로 가장 많이 표현도 가능하지만
min으로 항상 최소값만 update하여 dp[n]값에 넣어준다.

2번째 for loop에서는
이문제의 핵심인 제곱의 합으로 표현되므로
2제곱부터 sqrt(n)까지 조합만으로 Big(O) 를 줄여준다.


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