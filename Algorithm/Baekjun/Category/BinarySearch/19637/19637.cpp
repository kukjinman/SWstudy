#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<string, int>> v;
string name[100000];
int value[100000];

void binary_search(int item)
{
    int ans = 0;
    int s = 0;
    int e = n - 1;
    int mid = 0;
    while (s <= e)
    {
        mid = (s + e) / 2;

        if (item <= value[mid])
        {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }

    }

    // cout << " ans : " << ans +1 << endl;

    if (item > value[mid])
    {
        cout << name[mid + 1] << "\n";

    }
    else
    {
        cout << name[mid] << "\n";

    }
}

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> name[i] >> value[i];
    }

    // cout << " --------------------" << endl;

    for (int i = 0; i < m; i++)
    {
        int val = 0;
        cin >> val;
        binary_search(val);
    }


}




int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}
