#include <iostream>
#include <float.h>
#include<cmath>

using namespace std;

int N, K;

long double doll[501];

void solve()
{
	long double ans = DBL_MAX;


	for (int i = 0; i < N - K+1; i++)
	{

		long double mean = 0;
		long double sum = 0;
		long double var = 0;
		long double std_dev = 0;


		for (int j = i; j < i + K; j++)
		{
			
			sum += doll[j];
			//cout << "sum : " << sum << endl;


		}

		mean = sum / K;

		//cout << "mean : " << mean << endl;

		for (int j = i; j < i+ K; j++)
		{
			//var += pow((doll[j] - mean),2);

			var += (doll[j] - mean) * (doll[j] - mean);


			//cout << "[not doen] var : " << var << endl;


		}

		var /= K;
		//cout << "var : " << var << endl;

		std_dev = sqrt(var);
		//cout << "std_dev : " << std_dev << endl;

		if (ans > std_dev)
		{
			ans = std_dev;
		}



	}
	cout << ans << endl;


}


int main()
{
	cin >> N >> K;
	cout.precision(10);
	for (int i = 0; i < N; i++)
	{
		cin >> doll[i];
	}

	solve();

	return 0;

}