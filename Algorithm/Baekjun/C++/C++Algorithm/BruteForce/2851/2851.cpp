#include <cmath>
#include <iostream>

using namespace std;

int arr[11];

void solve()
{

    int sum = 0;

    sum += arr[0];

    for (int i = 1; i < 10; i++) {
        int cur = sum + arr[i];

        // cout << "cur : " << abs(100 - cur) << " next : " << abs(100 - sum) << endl;

        if (abs(100 - cur) <= abs(100 - sum)) {
            sum = cur;

        } else {
            break;
        }
    }

    cout << sum << endl;
}

int main()
{
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;
}