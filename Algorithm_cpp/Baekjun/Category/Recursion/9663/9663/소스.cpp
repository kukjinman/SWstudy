#include <iostream>
#include <cstring>

using namespace std;

int N;
int ans;
int map[16][16];


void input()
{
	cin >> N;

}



void updateMap(int y, int x)
{
	// y asix
	for (int i = 0; i < N; i++)
	{
		map[y][i] = 1;
	}

	//x asix
	for (int i = 0; i < N; i++)
	{
		map[i][x] = 1;
	}

	// left up

	for (int i = 0; i < N; i++)
	{
		int nx = x - i;
		int ny = y - i;

		//cout << " ny : " << ny << " nx : " << nx << endl;
		if (nx < 0 || ny < 0)
			break;
		else
			map[ny][nx] = 1;

	}

	// right up

	for (int i = 0; i < N; i++)
	{
		int nx = x + i;
		int ny = y - i;

		//cout << " ny : " << ny << " nx : " << nx << endl;
		if (nx >=N || ny < 0)
			break;
		else
			map[ny][nx] = 1;

	}

	// left down

	for (int i = 1; i < N; i++)
	{
		int nx = x - i;
		int ny = y + i;

		//cout << " ny : " << ny << " nx : " << nx << endl;
		if (nx < 0 || ny >= N)
			break;
		else
			map[ny][nx] = 1;

	}


	// right down

	for (int i = 0; i < N; i++)
	{
		int nx = x + i;
		int ny = y + i;

		//cout << " ny : " << ny << " nx : " << nx << endl;
		if (nx >= N || ny >= N)
			break;
		else 
			map[ny][nx] = 1;

	}



}


void map_printer()
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	cout << endl;

}

void recurse(int cnt)
{
	if (cnt == N)
	{
		ans += 1;
		cout << ans << endl;
		return;
	}


	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < N; j++)
		{

			if (map[i][j] != 0) {
				continue;
			}
			int buf_map[16][16];
			memcpy(buf_map, map, sizeof(buf_map));

			updateMap(i, j);
			

			map_printer();
			recurse(cnt + 1);

			memcpy(map, buf_map, sizeof(map));


		}



	}

	return;

}


void solve()
{

	recurse(0);



	//updateMap(2, 3);
	//map_printer();

}

int main()
{
	input();

	memset(map, 0, sizeof(map));
	solve();


	return 0;
}