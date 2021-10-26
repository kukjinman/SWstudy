#include <iostream>

using namespace std;
int main()
{

    int N = 0;

    int ans = 1;
    cin >> N;

    if (N == 0)
    {
        ans = 1;
        cout << ans << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++)
    {
        ans *= i;
    }

    cout << ans << endl;

    return 0;
}
