#include <iostream>

#include <queue>

int N;

using namespace std;

queue<int> q;

void input()
{
	cin >> N;
	for (int i = 1; i < N+1; i++)
	{
		q.push(i);


	}

}

void solve()
{
	int lastVal;
	int EndVal;

	while (!q.empty())
	{
		lastVal = q.front();
		q.pop();

		if (q.empty())
		{
			break;
		}
		else {
			EndVal = q.front();
			q.pop();
			q.push(EndVal);
		}


	}


	cout << lastVal;
}


int main()
{

	input();

	solve();






	return 0;
}


