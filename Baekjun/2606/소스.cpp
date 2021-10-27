#include <iostream>
#include <queue>
using namespace std;


int N, M;

#define MAX 1001

int adj[MAX][MAX];
int visited[MAX];

int VirusCount;

//for bfs
queue<int> q;

void input()
{
	cin >> N >> M;

	for (int i = 1; i < M + 1; i++)
	{

		int tempX;
		int tempY;

		cin >> tempX >> tempY;

		adj[tempX][tempY] = 1;
		adj[tempY][tempX] = 1;

	}


}

void dfs(int index)
{
	visited[index] = 1;

	for (int i = 1; i < N + 1; i++)
	{
		if (visited[i] == false && adj[index][i] == 1)
		{
			VirusCount++;

			dfs(i);
		}



	}


}


int main()
{

	input();

	dfs(1);

	cout << VirusCount;
	return 0;
}
