#include <iostream>
#include <math.h>

using namespace std;

int n;
int y = 0;
int x = 0;

int ans = 0;

void rec(int len_)
{

    // cout << " len : " << len_ << " ans = " << ans << endl;
    if (len_ == 1) {
        return;
    }

    if (y <= len_ / 2 - 1 && x <= len_ / 2 - 1) {

        ans += 0;
    } else if (y <= len_ / 2 - 1 && x <= len_ - 1) {
        ans += ((len_ / 2) * (len_ / 2));
        y -= len_ / 2;
    } else if (y <= len_ - 1 && x <= len_ / 2 - 1) {

        ans += ((len_ / 2) * (len_ / 2)) * 2;
        x -= len_ / 2;
    } else {

        ans += ((len_ / 2) * (len_ / 2)) * 3;
        y -= len_ / 2;
        x -= len_ / 2;
    }

    rec(len_ / 2);
}

int main()
{
    cin >> n;

    cin >> y >> x;

    cout << ":" << pow(2, 15) << endl;

    int len = pow(2, n);
    rec(len);

    cout << ans << endl;

    return 0;
}