#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int arr[20][20];
bool visited[20];
int n;
int ans = 1234567890;
int total_cnt = 0;
void combi(int cnt, int cur)
{
    if (cnt == n / 2) {
        int a = 0;
        int b = 0;
        // check
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (visited[i] && visited[j]) {
                    a += arr[i][j];
                    a += arr[j][i];
                } else if (!visited[i] && !visited[j]) {
                    b += arr[i][j];
                    b += arr[j][i];
                }

                cout << " i : " << i << " j : " << j << " a: " << a << " b: " << b << endl;
            }
        }
        ans = min(ans, abs(a - b));
    }
    for (int i = 0; i < n; i++) {
        cout << " [0i] : " << i << endl;

        if (visited[i] == false && i > cur) {
            total_cnt++;
            cout << "t:" << total_cnt << " [i] : " << i << endl;
            visited[i] = true;
            combi(cnt + 1, i);
            visited[i] = false;
            cout << "t:" << total_cnt << " [i] out : " << i << endl;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    combi(0, -1);
    cout << ans << endl;
}
