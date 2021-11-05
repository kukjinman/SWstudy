#include <iostream>

using namespace std;

int n, m;
int arr[256][256];
int arr_after[256][256];

int diff[256][256];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr_after[i][j];
		}
	}


}

void row_switcher()
{
	int arr_row[256];
	pair<int, int> first_max = { -1,0 }, second_max = { -1,0 };
	for (int i = 0; i < n; i++)
	{
		int row_cnt = 0;
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == arr_after[i][j])
			{
				diff[i][j] = 0;
			}
			else
			{
				diff[i][j] = 1;
				row_cnt++;
			}
		}

		arr_row[i] = row_cnt;

		if (arr_row[i] > first_max.second)
		{
			second_max = first_max;
			first_max.first = i;
			first_max.second = arr_row[i];
		}
		else if (arr_row[i] > second_max.second)
		{
			second_max.first = i;
			second_max.second = arr_row[i];
		}
	}

	cout << "[row] first_max : " << first_max.first << " second_max : " << second_max.first << endl;


	for (int j = 0; j < m; j++)
	{
		if (first_max.first != -1)
		{
			if (arr[first_max.first][j] == 0) {
				arr[first_max.first][j] = 1;
				//cout << "stage 1 : " << arr[first_max.first][j] << " ";
			}
			else {
				//cout <<" i "  <<first_max.first<< " stage 2[b] : " << arr[first_max.first][j] << " ";


				arr[first_max.first][j] = 0;

				//cout << "stage 2 : " << arr[first_max.first][j] << " ";
			}
		}

		if (second_max.second != -1)
		{
			if (arr[second_max.first][j] == 0) {
				arr[second_max.first][j] = 1;
			}
			else {
				arr[second_max.first][j] = 0;
			}
		}

	}


}
void column_switcher()
{
	int arr_col[256];
	pair<int, int> first_max = { -1,0 }, second_max = { -1,0 };
	for (int i = 0; i < m; i++)
	{
		int col_cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] == arr_after[j][i])
			{
				diff[j][i] = 0;
			}
			else
			{
				diff[j][i] = 1;
				col_cnt++;
			}
		}

		arr_col[i] = col_cnt;

		if (arr_col[i] > first_max.second)
		{
			second_max = first_max;
			first_max.first = i;
			first_max.second = arr_col[i];
		}
		else if (arr_col[i] > second_max.second)
		{
			second_max.first = i;
			second_max.second = arr_col[i];
		}
	}
	cout << "[col] first_max : " << first_max.first << " second_max : " << second_max.first << endl;

}

void solve()
{

	row_switcher();
	memset(diff, 0, sizeof(diff));
	column_switcher();

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << diff[i][j] << " ";
		}
		cout << endl;
	}

	cout << "arr -----------------" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}


int main()
{
	input();

	solve();

}