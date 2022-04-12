#include <cstring>
#include <iostream>
using namespace std;

bool areFriends[10][10];
int n = 0;
int m = 0;

int countPairings(bool taken[10])
{
    int cur_student = -1;

    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            cur_student = i;
            break;
        }
    }
    if (cur_student == -1) {
        // cout << "return" << endl;
        return 1;
    }

    int ret = 0;

    for (int i = cur_student + 1; i < n; i++) {

        if (!taken[i] && areFriends[cur_student][i]) {
            taken[cur_student] = taken[i] = true;
            // cout << " [m]  cur : " << cur_student << " i : " << i << endl;

            ret += countPairings(taken);
            taken[cur_student] = taken[i] = false;
        }
    }

    return ret;
}

int main()
{

    int C;
    cin >> C;

    bool taken[10];

    for (int i = 0; i < C; i++) {

        cin >> n >> m;

        //초기화
        memset(areFriends, false, sizeof(areFriends));
        memset(taken, false, sizeof(taken));

        for (int j = 0; j < m; j++) {

            int first = 0;
            int second = 0;
            cin >> first >> second;
            areFriends[first][second] = areFriends[second][first] = true;
            // cout << " first : " << first << " second : " << second << endl;
        }

        // cout << "-----------------------------" << endl;
        cout << countPairings(taken) << endl;
    }

    return 0;
}