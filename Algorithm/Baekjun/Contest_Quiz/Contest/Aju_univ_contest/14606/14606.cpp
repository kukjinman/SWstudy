#include <iostream>

using namespace std;

long long ans = 0;

void recurse(long long n)
{
    long long left = 0;
    long long right = 0;

    if (n == 1)
        return;

    if ((n % 2) == 1) {
        left = n / 2;
        right = n / 2 + 1;
    } else {
        left = n / 2;
        right = n / 2;
    }

    ans += left * right;

    recurse(left);
    recurse(right);
}

int main()
{
    long long num = 0;
    cin >> num;

    recurse(num);

    cout << ans << endl;

    return 0;
}