#include <iostream>
#include <queue>

using namespace std;


//N = y M = x
int N, M;

#define MAX 1001
int map[MAX][MAX];
int visited[MAX][MAX];

queue<pair<int, int>> q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void input() {

	cin >> N >> M;


	for (int j = 0; j < N; j++)
	{
		string temp;
		cin >> temp;

		for (int i = 0; i < M; i++)
		{

			map[j][i] = temp[i] - 48;

			//cout << temp << endl;
		}


	}



}

void printing()
{

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
		{
			
			cout << map[j][i];
		}
		cout << endl;


	}


}


void bfs()
{
	q.push(make_pair(0, 0));
	visited[0][0] = 1;

	int hammer = 1;


	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		//cout << "-----------------------------" << endl;
		//cout << "y : " << y << " x : " << x << endl;
		bool hammerUsed = false;

		for (int i = 0; i < 4; i++)
		{

			int ny = y + dy[i];
			int nx = x + dx[i];


			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			{

				continue;
			}
			else {

				if (map[ny][nx] == 0 && visited[ny][nx] == 0)
				{
					map[ny][nx] = map[y][x] +1;

					//cout << "[1]ny : " << ny << " nx : " << nx << endl;

					q.push(make_pair(ny, nx));
					visited[ny][nx] = 1;

				}
				else if (map[ny][nx] == 1 && visited[ny][nx] == 0 && hammer ==1)
				{
					//cout << "[2]ny : " << ny << " nx : " << nx << endl;

					map[ny][nx] = 0;
					hammerUsed = true;
					q.push(make_pair(y, x));
				}



			}

			if (i == 3 && hammerUsed == true)
			{
				hammer = 0;
			}

		}



	}
	
	if (map[N - 1][M - 1] == 0)
	{
		cout << -1;
		return;

	}

	cout << map[N - 1][M - 1] + 1;

}

int main() {

	input();

	bfs();

	//printing();
}



