#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N;

int board[21][21];

int res = 0;
int total = 0;

void board_printer()
{
    cout << "[board printer]" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

void shift(int cmd)
{

    queue<int> q;

    //왼쪽 sweep left
    if (cmd == 0) {

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {
                if (board[i][j]) {
                    // q에 sweep시 사용될 값들 저장
                    q.push(board[i][j]);
                    //해당 보드에 0으로 세팅
                    board[i][j] = 0;
                }
            }

            int index = 0;

            while (!q.empty()) {
                int val = q.front();
                q.pop();

                if (board[i][index] == 0) {
                    //index 증가 안시킴 기존에 자리에 기존 data set

                    board[i][index] = val;
                } else if (board[i][index] == val) {

                    // queue의 value가 해당 board자리와 value가 같아 2배로 증가
                    // 다음 자리로 이동하기 위해 index++시킴
                    board[i][index] *= 2;
                    index++;
                } else {
                    //해당 board의 data가 queue의 값과 다름
                    //index로 다음 위치 이동
                    //다음 위치 보드의 자리는 0이기 때문에 ==0일때와 같은 작업
                    index++;
                    board[i][index] = val;
                }
            }
        }

        // board_printer();
        // total++;
    }

    // 위로 sweep up
    else if (cmd == 1) {

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {
                if (board[j][i]) {
                    // q에 sweep시 사용될 값들 저장
                    q.push(board[j][i]);
                    //해당 보드에 0으로 세팅
                    board[j][i] = 0;
                }
            }

            int index = 0;

            while (!q.empty()) {
                int val = q.front();
                q.pop();

                if (board[index][i] == 0) {
                    board[index][i] = val;
                } else if (board[index][i] == val) {
                    board[index][i] *= 2;
                    index++;
                } else {
                    index++;
                    board[index][i] = val;
                }
            }
        }

        // board_printer();
        // total++;

    } else if (cmd == 2) {

        for (int i = 0; i < N; i++) {

            for (int j = N - 1; j >= 0; j--) {
                if (board[i][j]) {
                    // q에 sweep시 사용될 값들 저장
                    q.push(board[i][j]);
                    //해당 보드에 0으로 세팅
                    board[i][j] = 0;
                }
            }

            int index = N - 1;

            while (!q.empty()) {
                int val = q.front();
                q.pop();

                if (board[i][index] == 0) {
                    board[i][index] = val;
                } else if (board[i][index] == val) {
                    board[i][index] *= 2;
                    index--;
                } else {
                    index--;
                    board[i][index] = val;
                }
            }
        }

        // board_printer();
        // total++;

    } else if (cmd == 3) {

        for (int i = 0; i < N; i++) {

            for (int j = N - 1; j >= 0; j--) {
                if (board[j][i]) {
                    // q에 sweep시 사용될 값들 저장
                    q.push(board[j][i]);
                    //해당 보드에 0으로 세팅
                    board[j][i] = 0;
                }
            }

            int index = N - 1;

            while (!q.empty()) {
                int val = q.front();
                q.pop();

                if (board[index][i] == 0) {
                    board[index][i] = val;
                } else if (board[index][i] == val) {
                    board[index][i] *= 2;
                    index--;
                } else {
                    index--;
                    board[index][i] = val;
                }
            }
        }

        // board_printer();
        // total++;
    }

    // board_printer();
    // total++;
}
void dfs(int cnt)
{

    if (cnt >= 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res = max(res, board[i][j]);
            }
        }
        return;
    }
    // cout << "max : " << res << endl;

    //여기서 board buf를 define한 이유는
    //횟수별 shift로 변경된 보드의 max값을 이전에 확인하고,
    //다음 shift를 위하여 shift전의 board 상태로 되돌려 놓는
    //작업을 위해 buf에 저장해 놓는 작업

    //횟수에 따라 새로 define되어 횟수마다 board_buf의 값은 다르다.
    int board_buf[21][21];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board_buf[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        shift(i);

        dfs(cnt + 1);

        //shift 이전으로 board의 원상 복구
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = board_buf[i][j];
            }
        }
    }
}

int main(void)
{

    cin >> N;

    for (int i = 0; i < N; i++)

        for (int j = 0; j < N; j++)

            cin >> board[i][j];

    dfs(0);
    // cout << total << endl;
    cout << res << endl;

    return 0;
}
