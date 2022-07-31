#include <iostream>
using namespace std;

int n = 0, m = 0;
int num[100001];

int checker(int mid_)
{

    int cur = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {

        if (cur > num[i]) {
            cur -= num[i];

        }
        else {

            cur = mid_;
            cnt++;
            cur -= num[i];
        }
    }

    if (cnt == m) {
        // Answer!!
        return 0;
    }
    else if (cnt > m) {
        // Retry
        // 잘게 나누어짐
        return 1;
    }
    else {
        // cnt가 부족 함
        return -1;
    }
}

int binary_search()
{
    int ret = 0;

    int s = 0, e = 10000;
    int mid = 0;

    while (s < e) {

        mid = (s + e) / 2;

        if (checker(mid) == 0) {
            ret = mid - 1;
            break;
        }
        else if (checker(mid) == 1) {
            s = mid + 1;

        }
        else {

            e = mid - 1;
        }
    }

    return ret;
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << binary_search() << endl;
}