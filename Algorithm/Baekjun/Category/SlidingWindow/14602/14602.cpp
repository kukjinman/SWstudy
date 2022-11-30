#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k, w;

vector<vector<int>> map;

void input()
{
    map.resize(m, vector<int>(n, 0));


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp = 0;
            cin >> tmp;
            map[i][j] = tmp;
        }
    }

    // for(int i = 0; i < m;i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }


}

void solve()
{
    for (int i = 0; i < m - w + 1; i++)
    {
        for (int j = 0; j < n - w + 1; j++)
        {
            vector<int> v;
            for (int col = 0; col < w; col++)
            {
                for (int row = 0; row < w; row++)
                {
                    v.push_back(map[i + col][j + row]);
                }
            }
            sort(v.begin(), v.end());

            int median = v[v.size() / 2];
            cout << median << " ";


        }
        cout << endl;
    }


}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k >> w;

    input();
    solve();


    return 0;
}