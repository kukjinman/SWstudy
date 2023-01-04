#include <iostream>

using namespace std;

int c;

char board[6][6];

string word[11];

int dx[9] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[9] = { 1, 1, 0, -1, -1, -1, 0, 1 };



void printer()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            cout << board[i][j];
        }

        cout << endl;
    }
}

int bfs(int x, int y, string cur_word_, int index)
{
    cout << "index :  " << index << endl;

    if (index >= cur_word_.length()) {
        cout << " yes" << endl;
        return 1;
    }

    if (x < 0 || x >= 5 || y < 0 || y >= 5) {
        return 0;
    }

    if (board[y][x] != cur_word_.at(index)) {

        // cout << "y : " << y << " x : " << x << " cur char : " << board[y][x] << endl;
        // cout << "cur word : " << cur_word_ << " char : " << cur_word_.at(index) << endl;
        return 0;
    } else {
        cout << "if moon index : " << index << endl;
        // cout << "y : " << y << " x : " << x << endl;
        cout << "cur word : " << cur_word_ << " char : " << cur_word_.at(index) << endl;
    }

    for (int i = 0; i < 9; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int temp_idx = index + 1;
        cout << "y : " << y << " x : " << x << "ny : " << ny << " nx : " << nx << endl;

        if (bfs(nx, ny, cur_word_, temp_idx)) {
            return 1;
        }
    }
}

int solve(int n_)
{
    for (int z = 0; z < n_; z++) {

        int ret = 0;

        string cur_word = word[z];
        cout << cur_word << " ";

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << " ----------------------------------" << endl;
                if (bfs(j, i, cur_word, 0)) {

                    break;
                }
            }
        }


    }
}

int main()
{
    cin >> c;

    for (int z = 0; z < c; z++) {

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char tmp = ' ';
                cin >> tmp;

                board[i][j] = tmp;
            }
        }

        int n = 0;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> word[i];
        }
        int ret = 0;
        ret = solve(n);
        if (ret == 1) {

            cout << "YES" << endl;
        } else {

            cout << "NO" << endl;
        }
    }

    return 0;
}