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


    //�ٸ�������� �޸� while���� Ż�� break�� ����
    //�� ������ s�� e�� while Ż�� ������ ��ī���� �ִ� ���ڼ��� ������ ����
    // if���� ����� �ξ� Ż���ϱ� �����̴�.
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
