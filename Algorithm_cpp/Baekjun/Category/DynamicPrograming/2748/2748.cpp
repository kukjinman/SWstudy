#include <iostream>

using namespace std;

int main()
{
    long long num[10001] = {
        0,
    };
    num[0] = 0;
    num[1] = 1;
    num[2] = 1;

    int n = 0;
    cin >> n;

    for (int i = 3; i <= n; i++) {
        num[i] = num[i - 1] + num[i - 2];
    }

    cout << num[n] << endl;
    return 0;
}