#include <iostream>
#include <queue>

#define MAX 1001
int map[MAX][MAX];
int visited[MAX][MAX];

int N, M;

using namespace std;

queue < pair<int, int>> q;

int dx[4] = {-1 , 1 , 0 , 0 };
int dy[4] = {0, 0, -1,1 };




void input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}



	}



}

void initChecker()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//cout << " i = " << i << " j " << j << endl;
			
			
			if( map[i][j] == 1)
			q.push(make_pair(i, j));

		}
	}
}

void bfs()
{
	
	
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		visited[y][x] = 1;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];


			if (nx < 0 || nx >= N || ny <0 || ny > M)
			{
				continue;
			}
			else
			{


				if (map[ny][nx] == 0  && visited[ny][nx] != 1)
				{
					map[ny][nx] = map[y][x] + 1;
					q.push(make_pair(ny, nx));
					visited[ny][nx] = 1;


				}






			}



		}





	}




}

void solve()
{
	int sol_max = 0;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{

			//cout << map[i][j];

			if (map[i][j] == 0)
			{
				cout << -1 << endl;
				return;
			}
			else {

				if (map[i][j] > sol_max)
				{
					sol_max = map[i][j];


				}


			}

		}


		//cout << endl;
	}
	

	cout << sol_max-1 << endl;

}

int main()
{

	input();

	initChecker();

	bfs();

	solve();

	return 0;
}