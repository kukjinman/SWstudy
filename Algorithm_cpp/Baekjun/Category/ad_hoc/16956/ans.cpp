#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int R, C;
bool flag;
char arr[500][500];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

// 예제의 output과는 다른 답변
// 단순 wolf가 있는 주변을 벽으로 다 세워 막아버리는 코드

int main(void)
{
    cin >> R >> C;
    queue<pair<int, int>> wo;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'W') {
                wo.push({ i, j });
            }
        }
    }

    while (!wo.empty()) {
        int y = wo.front().first;
        int x = wo.front().second;
        wo.pop();

        for (int i = 0; i < 4; i++) {
            int newy = y + dy[i];
            int newx = x + dx[i];

            if (newy >= 0 && newy < R && newx >= 0 && newx < C) {
                if (arr[newy][newx] == '.') {
                    arr[newy][newx] = 'D';
                } else if (arr[newy][newx] == 'S') {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }

    cout << 1 << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}