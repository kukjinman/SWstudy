#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n = 0;
vector<int> v;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        v.push_back(num);
    }

    int s = 0; int e = n - 1;
    int cur = 0;
    int ans = 0;
    while (s < e)
    {
        cur = (e - s - 1) * (min(v[s], v[e]));
        // cout << cur << endl;
        if (v[s] < v[e])
        {
            s++;
        }
        else
        {
            e--;
        }

        if (ans < cur)
        {
            ans = cur;
        }
    }

    cout << ans << endl;

    return 0;
}