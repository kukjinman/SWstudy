#include <iostream>
#include <vector>

using namespace std;

int T;
int a, b;

int p_2017[21] = { 500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,
10,10,10,10,10,10 };

int p_2018[31] = { 512,256,256,128,128,128,128,64,64,64,64,64,64,64,64,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32 };




int solve()
{
	int ret = 0;

	//cout << "a :  " << a << " b : " << b << endl;

	if(a>=1 && a<=21)
	{
		ret += p_2017[a-1];

		//cout << "a ret : " << ret << endl;
	}


	if (b >= 1 && b <= 31)
	{
		ret += p_2018[b-1];

		//cout << "b ret : " << ret << endl;
	}

	return ret * 10000;

}


int main()
{

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		//cout << " =======" << endl;
		int ans = 0;
		cin >> a >> b;

		ans = solve();

		cout << ans << endl;

	}


	return 0;
}