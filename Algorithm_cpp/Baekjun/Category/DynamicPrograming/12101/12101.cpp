#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

/*
즉 n 번째에서 1,2,3의 합으로 이루어진 경우는
n-1 번째에서 각각의 값에 1을 더하는 경우
n-2 번째에서 각각의 값에 2를 더하는 경우
n-3 번째에서 각각의 값에 3을 더하는 경우로 나타낼 수 있다.
*/

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    vector<string> v[14];

    v[1].push_back("1");
    v[2].push_back("1+1");
    v[2].push_back("2");
    v[3].push_back("1+2");
    v[3].push_back("1+1+1");
    v[3].push_back("2+1");
    v[3].push_back("3");

    for (int i = 4; i <= n; i++)
    {
        // cout << " i : " << i << "------------" << endl;
        for (int j = 1; j <= 3; j++)
        {
            for (auto dp : v[i - j])
            {
                string tmp = dp + "+" + to_string(j);

                v[i].push_back(tmp);
                // cout << " dp : " << tmp << endl;
            }
        }
    }


    sort(v[n].begin(), v[n].end());

    for (auto dp : v[n])
    {
        // cout << "dp v : " << dp << endl;  
    }

    if (v[n].size() >= k)
    {
        cout << v[n][k - 1] << endl;
    }
    else
    {
        cout << "-1" << endl;
    }



    return 0;
}
