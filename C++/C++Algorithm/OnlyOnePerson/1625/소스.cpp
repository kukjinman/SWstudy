#include <cstring>
#include <deque>
#include <iostream>

using namespace std;

int n, m;
int arr_orig[256][256];
int arr[256][256];
int arr_after[256][256];

int row_first = -1;
pair<int, int> col_first = { -1, -1 };

int diff[256][256];

deque<int> row_q;
deque<pair<int, int>> col_q;

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr_orig[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr_after[i][j];
        }
    }
}

// void row_switcher_old(const int a, const int b)
// {
// 	for (int j = 0; j < m; j++)
// 	{
// 		if (a != -1)
// 		{
// 			if (arr[a][j] == 0) {
// 				arr[a][j] = 1;
// 				//cout << "stage 1 : " << arr[first_max.first][j] << " ";
// 			}
// 			else {
// 				//cout <<" i "  <<first_max.first<< " stage 2[b] : " << arr[first_max.first][j] << " ";

// 				arr[a][j] = 0;

// 				//cout << "stage 2 : " << arr[first_max.first][j] << " ";
// 			}
// 		}

// 		if (b != -1)
// 		{
// 			if (arr[b][j] == 0) {
// 				arr[b][j] = 1;
// 			}
// 			else {
// 				arr[b][j] = 0;
// 			}
// 		}

// 	}

// }

void row_switcher(const int a)
{
    for (int j = 0; j < m; j++) {
        if (a != -1) {
            if (arr[a][j] == 0) {
                arr[a][j] = 1;
                //cout << "stage 1 : " << arr[first_max.first][j] << " ";
            } else {
                //cout <<" i "  <<first_max.first<< " stage 2[b] : " << arr[first_max.first][j] << " ";

                arr[a][j] = 0;

                //cout << "stage 2 : " << arr[first_max.first][j] << " ";
            }
        }
    }
}

// void row_checker_old()
// {
// 	int arr_row[256];
// 	pair<int, int> first_max = { -1,0 }, second_max = { -1,0 };
// 	for (int i = 0; i < n; i++)
// 	{
// 		int row_cnt = 0;
// 		for (int j = 0; j < m; j++)
// 		{
// 			if (arr[i][j] == arr_after[i][j])
// 			{
// 				diff[i][j] = 0;
// 			}
// 			else
// 			{
// 				diff[i][j] = 1;
// 				row_cnt++;
// 			}
// 		}

// 		arr_row[i] = row_cnt;

// 		if (arr_row[i] > first_max.second)
// 		{
// 			second_max = first_max;
// 			first_max.first = i;
// 			first_max.second = arr_row[i];
// 		}
// 		else if (arr_row[i] > second_max.second)
// 		{
// 			second_max.first = i;
// 			second_max.second = arr_row[i];
// 		}
// 	}

// 	cout << "[row] first_max : " << first_max.first << " second_max : " << second_max.first << endl;

//     row_switcher(first_max.first, second_max.first);

// }

void row_checker()
{
    int arr_row[256];
    pair<int, int> first_max = { -1, 0 };
    for (int i = 0; i < n; i++) {
        if (row_first == i)
            continue;

        int row_cnt = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == arr_after[i][j]) {
                diff[i][j] = 0;
            } else {
                diff[i][j] = 1;
                row_cnt++;
            }
        }

        arr_row[i] = row_cnt;

        if (arr_row[i] > first_max.second) {
            row_first = i;
            first_max.first = i;
            first_max.second = arr_row[i];
        }
    }

    // cout << "[row] first_max : " << first_max.first << endl;
    row_q.push_back(first_max.first + 1);

    row_switcher(first_max.first);
}

void column_switcher(const int a, const int b)
{
    int temp[256];

    for (int i = 0; i < n; i++) {

        temp[i] = arr[i][a];
        arr[i][a] = arr[i][b];
        arr[i][b] = temp[i];
    }
}

void column_checker()
{
    int arr_col[256];
    // -1 index for checking needed to be changed or not.
    pair<int, int> first_max = { -1, 0 }, second_max = { -1, 0 };

    for (int i = 0; i < m; i++) {
        if (col_first.first == i || col_first.second == i)
            continue;

        int col_cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == arr_after[j][i]) {
                diff[j][i] = 0;
            } else {
                diff[j][i] = 1;
                col_cnt++;
            }
        }

        arr_col[i] = col_cnt;

        if (arr_col[i] > first_max.second) {
            second_max = first_max;
            first_max.first = i;
            first_max.second = arr_col[i];
        } else if (arr_col[i] > second_max.second) {
            second_max.first = i;
            second_max.second = arr_col[i];
        }
    }
    // cout << "[col] first_max : " << first_max.first << " second_max : " << second_max.first << endl;

    col_first.first = first_max.first;
    col_first.second = second_max.first;
    col_q.push_back(make_pair(first_max.first + 1, second_max.first + 1));

    column_switcher(first_max.first, second_max.first);
}

bool ans_checker()
{

    // cout << "arr -----------------" << endl;

    // for (int i = 0; i < n; i++)
    // {
    // 	for (int j = 0; j < m; j++)
    // 	{
    // 		cout << arr[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }

    // cout << "arr_after -----------------" << endl;

    // for (int i = 0; i < n; i++)
    // {
    // 	for (int j = 0; j < m; j++)
    // 	{
    // 		cout << arr_after[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }

    // cout << " -----------------" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (arr[i][j] != arr_after[i][j]) {
                // cout << "not equal " << endl;
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    int switch_cnt = 0;
    int all_case_cnt = 0;
    memcpy(arr, arr_orig, sizeof(arr));

    while (!ans_checker()) {

        if (switch_cnt >= 4) {
            // cout << " switch cnt reached over 4" << endl;
            all_case_cnt++;
            memcpy(arr, arr_orig, sizeof(arr));
            row_first = -1;
            col_first = make_pair(-1, -1);
            switch_cnt = 0;

            row_q.clear();
            col_q.clear();
        }

        if (all_case_cnt == 0) {

            // row -> col -> row -> col
            if ((switch_cnt % 2) == 0) {
                //even switch_cnt for row switcher
                row_checker();
            } else {
                //old switch_cnt for col switcher
                column_checker();
            }

            switch_cnt++;
            memset(diff, 0, sizeof(diff));
        } else if (all_case_cnt == 1) {
            // col -> row -> col -> row
            if ((switch_cnt % 2) == 0) {
                //old switch_cnt for col switcher
                column_checker();

            } else {
                //even switch_cnt for row switcher
                row_checker();
            }

            switch_cnt++;
            memset(diff, 0, sizeof(diff));
        } else if (all_case_cnt == 2) {
            // row -> row -> col -> col
            if (switch_cnt < 2) {
                row_checker();

            } else {
                column_checker();
            }

            switch_cnt++;
            memset(diff, 0, sizeof(diff));
        } else if (all_case_cnt == 3) {
            // col -> col -> row -> row
            if (switch_cnt < 2) {
                column_checker();
            } else {
                row_checker();
            }

            switch_cnt++;
            memset(diff, 0, sizeof(diff));
        } else {
            // cout << "no ans" << endl;
            break;
        }
    }

    // bool ret = ans_checker();
    // cout << "ret : " << ret << endl;
    // cout << endl;

    // for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             cout << diff[i][j] << " ";
    //         }
    //         cout << endl;
    // }

    // cout << "arr -----------------" << endl;

    // for (int i = 0; i < n; i++)
    // {
    // 	for (int j = 0; j < m; j++)
    // 	{
    // 		cout << arr[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }

    // cout << "row_q size : " << row_q.size() << " col_q size : " << col_q.size() << endl;
    cout << row_q.size() + col_q.size() << endl;

    while (!row_q.empty()) {
        cout << "0 " << row_q.front() << endl;
        row_q.pop_front();
    }

    while (!col_q.empty()) {
        cout << "1 " << col_q.front().first << " " << col_q.front().second << endl;
        col_q.pop_front();
    }
}

int main()
{
    input();

    solve();
}