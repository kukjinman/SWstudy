#include <iostream>
#include <stdio.h>
#include <queue>


int N, M;

using namespace std;

#define MAX 100

int map[MAX][MAX];

int visited[MAX][MAX];
queue<pair<int, int>> q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			temp = scanf_s("%1d", &map[i][j]);

		}


	}
	cout << endl;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << map[i][j];


	//	}


	//	cout << endl;
	//}



}

void printingMap()
{


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << visited[i][j];


		}


		cout << endl;
	}



}


void bfs(int y, int x)
{
	q.push(make_pair(y ,x));
	visited[y][x] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;


		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			cout << "stage 1 " << endl;

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			{
				cout << "stage 2 " << endl;

				continue;
			}
			else {

				if (map[ny][nx] == 1 && visited[ny][nx] == 0)
				{
					visited[ny][nx] = visited[y][x] + 1;
					q.push(make_pair(ny, nx));
					printingMap();
				}

			}



		}


	}

}




int main()
{
	input();
	

	bfs(0, 0);
	cout << visited[N - 1][M - 1] <<endl;

	return 0;
}