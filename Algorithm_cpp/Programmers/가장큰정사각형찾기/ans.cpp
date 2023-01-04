#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// DP문제
// sol.cpp 접근은 brute force로 performance가 좋지 않다.

// 다음부터는 memory를 사용해서 dp로 풀수있는지 일정한 pattern까지 알아냈으면
// 한번 사용할 생각을 해보자.

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int r = board.size();
    int c = board[0].size();

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (board[i][j] == 1) {
                board[i][j] = 1 + min({ board[i - 1][j - 1], board[i - 1][j], board[i][j - 1] });
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}