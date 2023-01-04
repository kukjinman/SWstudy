#include <iostream>
#include <vector>

using namespace std;

int n, k;

vector<int> v;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        if (tmp == 1)
            v.push_back(i);
    }

    if (v.size() < k)
    {
        cout << -1;
        return 0;
    }

    int min = 10000001;
    for (int i = 0; i <= v.size() - k; i++)
    {
        if (v[i + k - 1] - v[i] < min)
        {
            // cout << " min : " << min << " cur : " << v[i + k -1] - v[i] << endl;
            min = v[i + k - 1] - v[i];
        }
    }

    cout << min + 1;

    return 0;
}