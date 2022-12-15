#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[100003];

void input()
{
    cin >> n >> m;

    arr[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> arr[i];
    }
    arr[m + 1] = n;
}

void binaray_search()
{
    int s = 0;
    int e = n;
    int mid;
    int ans = 100002;
    while (s <= e)
    {
        mid = (s + e) / 2;
        // cout << " mid : " << mid << endl;
        bool isAvailable = true;


        for (int i = 0; i <= m; i++)
        {
            if (i == 0 || i == m)
            {
                if (arr[i + 1] - arr[i] > mid)
                {
                    isAvailable = false;
                    break;
                }
            }


            if (arr[i + 1] - arr[i] > mid * 2)
            {
                isAvailable = false;
                break;
            }


        }

        if (isAvailable == true)
        {
            // cout << " e : " << e << endl;
            e = mid - 1;
        }
        else
        {
            // cout << " s : " << s << endl;
            s = mid + 1;
        }

        ans = s;


    }
    cout << ans << endl;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    binaray_search();

    return 0;
}
