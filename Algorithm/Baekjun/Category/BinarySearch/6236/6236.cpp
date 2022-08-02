#include <algorithm>
#include <iostream>

using namespace std;

int n = 0, m = 0;
int num[100001] = {
    0,
};

int sum = 0;

int checker(int mid_)
{

    int cur = mid_;
    int cnt = 1;

    for (int i = 0; i < n; i++) {

        if (cur >= num[i]) {
            cur -= num[i];
        }
        else {

            cur = mid_;
            cnt++;
            cur -= num[i];
        }
    }

    if (cnt <= m) {
        return 0;
    }
    else {
        return 1;
    }
}

int binary_search()
{
    int ret = 0;

    int s = *max_element(num, num + n);
    int e = sum;
    int mid = 0;

    while (s <= e) {

        mid = (s + e) / 2;
        // cout << " mid : " << mid << endl;
        if (checker(mid) == 0) {

            e = mid - 1;

        }
        else {
            s = mid + 1;
        }
    }

    return mid;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
    }

    cout << binary_search() << endl;
}