#include <iostream>

using namespace std;

bool areFriends[10][10];
int n = 0;
int m = 0;

int countPairings(bool taken[10])
{
    bool finished = true;
    for (int i = 0; i < n; ++i)
        if (!taken[i])
            finished = false;
    if (finished)
        return 1;

    int ret = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if (!taken[i] && !taken[j] && areFriends[i][j]) {
                taken[i] = taken[j] = true;
                ret += countPairings(taken);
                taken[i] = taken[j] = false;
            }
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

        for (int j = 0; j < m; j++) {

            int first = 0;
            int second = 0;
            cin >> first >> second;
            areFriends[first][second] = areFriends[second][first] = true;
        }

        cout << countPairings(taken) << endl;
    }

    return 0;
}