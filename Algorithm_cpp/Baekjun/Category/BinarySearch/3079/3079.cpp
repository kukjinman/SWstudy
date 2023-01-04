#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

unsigned long long n, m;

/*
7 7 7 7
------- ------- ------- ------- (28)
10 10 10
---------- ---------- ---------- (30)
                               | <- 이 day의 bar를 좌우로 옮기면서 해당 심사 6명을 만족시키는
                                 최소 day를 찾으면 된다. 따라서 binary search로 최소 day를 찾으면 됨.
여기서 6명의 심사를 최소 시간에 하기 위해서

위와 같은 방법을 사용하는 이유는
빈자리에 채워주는 식으로 하면 위와 같이
10T짜리의 칸이 먼저 비고 결국에는 10만큼의 시간이 소요되어
1초를 기다린 7 대기소보다 오래걸림.

*/
unsigned long long T[100000];
unsigned long long ans = 0;

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
    }
}

unsigned long long checker(unsigned long long mid_)
{
    unsigned long long ret = 0;

    for (int i = 0; i < n; i++)
    {
        // cout << " T : " << T[i] << " mid_ :  " << mid_ << " res : " << mid_/T[i] << endl;
        ret += mid_ / T[i];
    }

    return ret;
}

void solve()
{

    sort(T, T + n);

    unsigned long long s = 1;
    unsigned long long e = T[0] * m;
    unsigned long long mid = 0;;
    // cout << " m " << m << " ele : " << T[0] << endl;
    // cout << "[0] s : " << s << " e : " << e << " mid : " << mid << endl;


    while (s <= e)
    {
        mid = (s + e) / 2;
        unsigned long long cnt = checker(mid);
        // cout << " cnt : " << cnt << endl;
        if (cnt >= m)
        {
            // 같은경우에는 최소값을 위해 계속 e를 줄여줘야한다.
            // cout << "[>=] s : " << s << " e : " << e << " mid : " << mid << endl;

            if (ans == 0 | ans > mid)
            {
                ans = mid;
            }


            e = mid - 1;
        }
        else
        {
            // cout << "[<] s : " << s << " e : " << e << " mid : " << mid << endl;

            s = mid + 1;
        }

    }

    cout << ans << endl;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();

    return 0;
}
