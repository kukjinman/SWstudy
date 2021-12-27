#include <iostream>
#include <queue>
#include <math.h>
#include<cstring>

using namespace std;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

#define MAX 101

int arr[MAX][MAX];
int visited[MAX][MAX];
int N;

int min_num;
int max_num;


void input()
{

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];

			min_num = min(min_num, arr[i][j]);
			max_num = max(max_num, arr[i][j]);
		}
	}
}

void printer()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}

}

void bfs(int x, int y , int height)
{
	queue <pair<int, int>> q;
	visited[x][y] = 1;
	q.push(make_pair(x, y));


	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx > N || ny < 0 || ny > N) continue;
			if (visited[nx][ny] == 1) continue;

			if (arr[nx][ny] > height) {

				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));

			}

		}


	}




}

void solve()
{
	int result = 0;
	int cnt = 0;

	for (int i = min_num; i < max_num; i++)
	{
		//cout << "min : " << min_num << " max : " << max_num << endl;
		memset(visited, 0, sizeof(visited));

		for (int j = 0; j < N; j++)
		{

			for (int k = 0; k < N; k++)
			{

				if (arr[j][k] > i && visited[j][k] == 0)
				{
					bfs(j,k, i);
					cnt++;
					//cout << "i : " <<  i << "arr : " << arr[j][k] << endl;
					//cout << "cnt : " << cnt << endl;

				}
				else {
					//cout << "[else] i : " << i << "arr : " << arr[j][k] << endl;

				}
			}
		}
		//cout << "----------------------------------------" << endl;
		if (result < cnt)
		{
			result = cnt;

		}
		cnt = 0;
	}

	cout << result << endl;
}

int main()
{
	input();
	//printer();

	solve();



}