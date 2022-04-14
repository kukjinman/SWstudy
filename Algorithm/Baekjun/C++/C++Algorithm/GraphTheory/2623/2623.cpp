#include <algorithm>
#include <iostream>

using namespace std;

int n, m;

int arr[1001][101];

int ans[1001];

int pointer = 1;

int solve()
{

    int buf[1001];

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (arr[i][j] == 0) {

                if (j == 0) {

                    return 1;
                }

                return 0;

            } else {
                buf[i] = arr[i][j];
            }

            if (j == m - 1) {
                sort(buf, buf + m);

                for (int z = pointer - 1; z < m; z++) {
                    ans[z] = buf[z - pointer + 1];
                }
                pointer *= m;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {

        int loop;

        cin >> loop;

        for (int j = 0; j < loop; j++) {

            int tmp = 0;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }

    if (solve()) {
        int cnt = 0;
        while (ans[cnt] != 0) {

            cout << ans[cnt++] << endl;
        }
    } else {
        cout << "0" << endl;
    }

    return 0;
}