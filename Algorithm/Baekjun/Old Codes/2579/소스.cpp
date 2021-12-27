#include <iostream>

using namespace std;

int n;
int arr[302];

int dp[302];

int main()
{
	cin >> n;

	for (int i = 1; i < n+1; i++)
	{
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	dp[4] = max(dp[2] + arr[4], dp[1] + arr[3] + arr[4]);
	dp[5] = max(dp[3] + arr[5], dp[2] + arr[4] + arr[5]);


	for (int i = 6; i < n + 1; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);

	}

	cout << dp[n] << endl;





	return 0;
}