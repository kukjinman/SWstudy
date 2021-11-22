#include <iostream>

int a, b, c;

using namespace std;

void input()
{

		cin >> a;
		cin >> b;
		cin >> c;



}

void solve()
{
	int sum = a * b * c;

	int numCounter[10] = {};

	while (sum > 0)
	{
		int curNum = -1;

		curNum = sum % 10;
		//cout << curNum << endl;

		numCounter[curNum] += 1;



		sum /= 10;
		
	}

	for (int i = 0; i < 10; i++)
	{

		cout << numCounter[i] << endl;


	}


}

int main()
{
	input();

	solve();


	return 0;
}