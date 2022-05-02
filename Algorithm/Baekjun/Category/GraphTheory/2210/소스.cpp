#include <iostream>
#include <set>
#include <cmath>

using namespace std;

set<int> s;

int map[6][6];


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };



void input()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			cin >> map[i][j];

		}

	}

}


void make_num(int y, int x, int cnt, int cur)
{

	if (cnt < 0)
	{
		s.insert(cur);
		return;
	}

	cur += map[y][x] * pow(10, cnt);

	//cout << " cnt : " << cnt << endl;
	//cout << "map : " << map[y][x] << " pow : " << pow(10, cnt) << endl;

	//cout << "cur : " << cur << endl;

	for (int i = 0; i < 4; i++)
	{

		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
		{
			continue;

		}

		make_num(ny, nx, cnt - 1, cur);


	}



}


void solve()
{

	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{
			
			make_num(i, j, 5, 0);


		}

	}

	cout << s.size() << endl;


}




int main()
{
	input();

	solve();


	return 0;
}