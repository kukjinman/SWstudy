#include <iostream>
#include <queue>
using namespace std;


int N, z;

queue<int> q;

void input()
{
	cin >> N >> K;

	for (int i = 1; i < N+1; i++)
	{
		q.push(i);

	}
}

void solve()
{
	cout << "<";
	while (!q.empty())
	{
		for (int i = 1; i < K; i++)
		{
			int temp;
			temp = q.front();
			q.pop();
			q.push(temp);
		}

		cout << q.front();
		q.pop();

		if (!q.empty())
		{
			cout << ", ";
		}

	}

	cout << ">";
}


int main()
{

	input();

	solve();

	return 0;
}
