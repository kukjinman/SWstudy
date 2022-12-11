#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<int> L;


int main(int argc, char** argv)
{

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        L.push_back(tmp);
    }

    int s = 0; int e = *max_element(L.begin(), L.end());

    //cout << "e : " << e << endl;


    //다른문제들과 달리 while문의 탈출 break가 없다
    //그 이유는 s와 e의 while 탈출 조건이 조카에게 주는 과자수가 부족한 경우로
    // if문을 만들어 두어 탈출하기 떄문이다.
    // 
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        //cout << " s : " << s << " mid :  " << mid << " e : " << e << endl;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            //cout << " L : " << L[i] << endl;
            if(mid != 0)
            cnt += L[i] / mid;
        }

        if (cnt >= m) {

            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }

    }

    cout << ans << endl;
    return 0;
}
