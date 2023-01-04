#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

/*
�� n ��°���� 1,2,3�� ������ �̷���� ����
n-1 ��°���� ������ ���� 1�� ���ϴ� ���
n-2 ��°���� ������ ���� 2�� ���ϴ� ���
n-3 ��°���� ������ ���� 3�� ���ϴ� ���� ��Ÿ�� �� �ִ�.
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
