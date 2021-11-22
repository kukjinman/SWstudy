
#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <string> 

using namespace std;


int N, M, V;

#define MAX 25

//string map[MAX];

int map[MAX][MAX];
int visited[MAX][MAX];


int dx[4] = { -1 , 1 , 0, 0 };
int dy[4] = { 0,0,-1,1 };

list<int> danjiCounter;

queue<pair<int, int>> q;

void input()
{
	cin >> N;


	for (int i = 0; i < N; i++)
	{

		string tempMap;


		cin >> tempMap;

		for (int j = 0; j < N; j++)
		{
			map[i][j] = (int)tempMap[j] - 48;


		}


	}


}


void bfs(int x, int y)
{
	q.push(make_pair(x, y));

	visited[x][y] = 1;

	int tempCounter = 1;

	while (!q.empty())
	{
		int X = q.front().first;
		int Y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{ 
			int NextX = X + dx[i];
			int NextY = Y + dy[i];

			if (NextX < 0 || NextX >= N || NextY < 0 || NextY >= N)
			{
				continue;
			}
			else {
				// Inside the boundary
				//cout << "X : " << NextX << "Y : " << NextY << endl;

				if (map[NextX][NextY] == 1 && visited[NextX][NextY] != 1)
				{

					q.push(make_pair(NextX, NextY));
					visited[NextX][NextY] = 1;

					//cout << "[s] X : " << NextX << "Y : " << NextY << endl;
					tempCounter++;
				}





			}

		}




	}

	danjiCounter.push_back(tempCounter);

	//cout << "-----------------------------------" << endl;
}
bool myfunction(int i, int j) { return (i < j); }


void solve()
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{


			if (map[i][j] == 1 && visited[i][j] != 1)
			{
				//cout << "[m]"<< map[i][j]<<endl;
				bfs(i, j);

			}

		}
	}
	danjiCounter.sort();

	//sort(danjiCounter.begin(), danjiCounter.end(), myfunction);
	cout << danjiCounter.size() << endl;
	for (auto item : danjiCounter)
	{
		cout << item << endl;
		//cout << danjiCounter.front() << endl;
	}
}


int main()
{
	danjiCounter.clear();
	input();

	solve();




	return 0;
}