#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int BOARD_SIZE = 5;

vector<pair<int, int>> aroundCoordinates = {

    make_pair(1, 0), // 우
    make_pair(1, 1), // 우상단
    make_pair(0, 1), // 상
    make_pair(-1, 1), // 좌상단
    make_pair(-1, 0), // 좌
    make_pair(-1, -1), // 좌하단
    make_pair(0, -1), // 하
    make_pair(1, -1) // 우하단

};

bool isRange(int x, int y)
{
    return (0 <= x && x < BOARD_SIZE) && (0 <= y && y < BOARD_SIZE);
}

int solve(const vector<vector<char>>& board, const string& s, int x, int y, int index)
{
    cout << "index :  " << index << endl;

    if (index >= s.length()) {
        return 1;
    }

    if (!isRange(x, y) || board[x][y] != s[index]) {
        return 0;
    } else if (board[x][y] == s[index]) {
        cout << "cur word : " << s << " char : " << s[index] << endl;
    }

    for (auto coordinate : aroundCoordinates) {
        int nx = x + coordinate.first;
        int ny = y + coordinate.second;
        int nextIndex = index + 1;
        cout << "y : " << x << " x : " << y << " ny : " << nx << " nx : " << ny << endl;

        if (solve(board, s, nx, ny, nextIndex)) {
            return 1;
        }
    }

    return 0;
}

bool solution(const vector<vector<char>>& board, const string& s)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (solve(board, s, i, j, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int C;
    cin >> C;

    if (!(0 < C && C <= 50)) {
        cout << "fail: Test Case Only Between 1 and 50" << endl;
        return 0;
    }

    for (int i = 0; i < C; i++) {
        auto board = vector<vector<char>>(BOARD_SIZE, vector<char>(BOARD_SIZE, '*'));

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                char c;
                cin >> c;
                board[i][j] = c;

                if (!(0 <= (c - 'A') && (c - 'A') <= 26)) {
                    cout << "fail: It only alphabet" << endl;
                    return 0;
                }
            }
        }

        int N;
        cin >> N;

        if (!(1 <= N && N <= 10)) {
            cout << "fail: N only between 1 and 10" << endl;
            return 0;
        }

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            bool res = solution(board, s);
            cout << s << " " << ((res) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
