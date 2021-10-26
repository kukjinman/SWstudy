#include <iostream>

using namespace std;
int main()
{

    long long N;
    int ans = 1;

    cin >> N;

    long long stage = 1;

    while (1)
    {

        if (N == 1)
        {
            break;
        }
        else
        {
            stage += 6 * ans;

            ans++;

            if (stage >= N)
            {

                break;
            }
        }

        // cout << "ans : " << ans << std::endl;
    }

    cout << ans;

    return 0;
}
