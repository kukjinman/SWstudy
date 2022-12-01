#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

int L[21];
int J[21];

// pq�� Ǯ��� �ȵǴ� ���� 
/*
3
10 10 99
1 3 5
10 3
10 1
99 5

5�� ����� �ִ��̳�, ���������� ������ 4�ۿ� ���� ����.

*/



// struct compare
// {
//     bool operator()(pair<int,int> a, pair<int,int> b)
//     {
//         if(a.first == b.first)
//         {
//             return a.second < b.second;
//         }
//         else
//         {
//             return a.first > b.first;
//         }
//     }
// };

// priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;


int ans = 0;

void dfs(int cnt, int max, int happy)
{

    if ((max >= 100) || cnt > n)
    {

        return;
    }
    else
    {
        if (ans < happy)
        {
            ans = happy;
            // cout <<"cnt : " << cnt << " ans : " << ans << " max : " << max << endl;

        }

    }

    for (int i = cnt; i <= n; i++)
    {
        int cur_max = max + L[i];
        int cur_happy = happy + J[i];
        dfs(i + 1, cur_max, cur_happy);


    }



}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> J[i];
    }

    dfs(0, 0, 0);

    cout << ans << endl;
    return 0;
}
