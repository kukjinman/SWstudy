#include <iostream>
#include <vector>

using namespace std;

// Not resolved
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, const char c)
    {
        for (int i = 0; i <= 9; i++) {

            if (board[row][i] == c) {

                cout << "[s1] row : " << row << " col : " << i << " c : " << c << endl;

                if (i == col)
                    continue;
                return false;
            }
        }

        for (int i = 0; i <= 9; i++) {

            if (board[i][col] == c) {
                cout << "[s2] row : " << i << " col : " << col << " c : " << c << endl;

                if (i == col)
                    continue;

                return false;
            }
        }

        for (int i = 0; i <= 9; i++) {

            if (board[(3 * (row / 3) + i / 3)][3 * (col / 3) + (i % 3)] == c) {

                cout << "[s3] row : " << (3 * (row / 3) + i / 3) << " col : " << 3 * (col / 3) + (i % 3) << " c : " << c << endl;
                return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {

                    if (isValid(board, i, j, board[i][j]) == false) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

// int main()
// {
//     Solution s;

//     vector<vector<char>> v;

//     char board[10][10] = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
//         { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
//         { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
//         { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
//         { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
//         { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
//         { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
//         { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
//         { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

//     for (int i = 0; i < 9; i++) {
//         for (int j = 0; j < 9; j++) {

//             v[i][j] = board[i][j];
//         }
//     }

//     s.isValidSudoku(v);

//     return 0;
// }
