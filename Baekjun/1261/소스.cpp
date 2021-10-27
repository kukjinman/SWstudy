#include <iostream>
#include <queue>


using namespace std;

#define MAX 101

int map[MAX][MAX];
int visited[MAX][MAX];
int N, M;

int dx[4] = { 1,-1, 0,0 };
int dy[4] = { 0,0, 1,-1 };

queue<pair<int, int>> q;

void input()
{
	cin >> N >> M;
	//x = N, y = M

	for (int i = 0; i < M; i++)
	{

		for (int j = 0; j < N; j++)
		{
			
			scanf_s("%1d", &map[i][j]);

		}
	}

}


void solve()
{
	q.push(make_pair(0, 0));
	visited[0][0] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}
			else {

				if (visited[ny][nx] == 1)
					continue;

				if (map[ny][nx] == 1)
				{
					map[ny][nx] = map[y][x] + 1;
					q.push(make_pair(nx, ny));
					visited[ny][nx] = 1;
				}
				else
				{
					q.push(make_pair(nx, ny));
					visited[ny][nx] = 1;

				}

			}

		}


	}


	cout << map[M-1][N-1] << endl;

}




int main()
{
	
	input();

	solve();


}