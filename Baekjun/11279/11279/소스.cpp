#include <iostream>
#include <queue>

#include <vector>

#include <algorithm>
#include <functional>

using namespace std;

int N;

priority_queue<int> q;

//priority_queue<int, vector<int>, less<int>> q;
vector<int> list;

bool myfunc(int i, int j) {
	return i < j;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int curNum;

		scanf("%d", &curNum);

		if (curNum == 0)
		{
			if (q.empty())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", q.top());
				q.pop();


			}

		}
		else
		{

			q.push(curNum);


		}



	}



	return 0;
}