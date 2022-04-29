#include <iostream>
#include <queue>

using namespace std;

char map[51][51];
int y = 0;
int x = 0;

void input()
{

    cin >> y >> x;

    for (int i = 0; i < y; i++) {

        string tmp;
        cin >> tmp;

        for (int j = 0; j < x; j++) {

            map[i][j] = tmp[j];
        }
    }

    // for (int i = 0; i < y; i++) {

    //     for (int j = 0; j < x; j++) {
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }
}

pair<int, int> finding_starting_point()
{

    for (int i = 0; i < y; i++) {

        for (int j = 0; j < x; j++) {
            if (map[i][j] == '0') {
                return make_pair(i, j);
                map[i][j] = '.';
            }
        }
        cout << endl;
    }

    return make_pair(-1, -1);
}

void solve()
{
    pair<int, int> start;
    start = finding_starting_point();

    // cout << " first " << start.first << " second : " << start.second << endl;
}

int main()
{
    input();

    solve();

    return 0;
}