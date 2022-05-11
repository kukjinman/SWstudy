#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

stack<int> st;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;

    for (int m : moves) {

        // x축 길이가 5개라고 고정 된 것이 아니다.
        // board[0].size()으로 적용 안되고 5로 하드코딩되면, test case 4, 7 ~ 부터 fail남
        for (int j = 0; j < board[0].size(); j++) {
            // cout << board[j][m - 1] << endl;

            if (board[j][m - 1] != 0) {
                if (!st.empty()) {
                    // cout << " st.top : " << st.top() << " b : " << board[j][m - 1] << endl;

                    if (st.top() == board[j][m - 1]) {

                        st.pop();
                        answer += 2;
                        // cout << " ans : " << answer << endl;
                    } else {

                        st.push(board[j][m - 1]);
                    }
                } else {

                    st.push(board[j][m - 1]);
                }
                board[j][m - 1] = 0;

                break;
            }
        }
        // cout << "------------------" << endl;
    }

    return answer;
}