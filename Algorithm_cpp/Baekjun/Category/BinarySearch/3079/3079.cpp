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
                               | <- �� day�� bar�� �¿�� �ű�鼭 �ش� �ɻ� 6���� ������Ű��
                                 �ּ� day�� ã���� �ȴ�. ���� binary search�� �ּ� day�� ã���� ��.
���⼭ 6���� �ɻ縦 �ּ� �ð��� �ϱ� ���ؼ�

���� ���� ����� ����ϴ� ������
���ڸ��� ä���ִ� ������ �ϸ� ���� ����
10T¥���� ĭ�� ���� ��� �ᱹ���� 10��ŭ�� �ð��� �ҿ�Ǿ�
1�ʸ� ��ٸ� 7 ���Һ��� �����ɸ�.

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
            // ������쿡�� �ּҰ��� ���� ��� e�� �ٿ�����Ѵ�.
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
