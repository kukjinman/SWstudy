#include <iostream>
#include <vector>

using namespace std;

int n = 0;

vector<long long> arr;

int main(int argc, char* argv[])
{
    cin >> n;
    int cnt = 0;

    long long prev = -1000000001;
    int critical_index = 0;
    int inverse_cnt = 0;

    for (int i = 0; i < n; i++)
    {

        long long cur = 0;
        cin >> cur;
        arr.push_back(cur);


    }

    for (int i = 0; i < n -1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            critical_index = i;
            inverse_cnt++;
 //           cout << " i : " << i << " inv : " << inverse_cnt << endl;
        }
     
    }


    if (inverse_cnt == 0)
    {
        cout << n;
    }
    else if (inverse_cnt == 1)
    {
        if (critical_index == n - 2)
        {
            if (arr[critical_index - 1] <= arr[critical_index + 1])
            {
                cout << 2;
            }
            else {
                cout << 1;
            }
        }
        else if (critical_index == 0)
        {
            if (arr[critical_index] <= arr[critical_index + 2])
            {
                cout << 2;
            }
            else {
                cout << 1;
            }

        }
        else {
            int cnt = 0;
            if (arr[critical_index - 1] <= arr[critical_index + 1])
            {
                cnt++;
            }

            if (arr[critical_index] <= arr[critical_index + 2])
            {
                cnt++;
            }
            cout << cnt;
        }


    }
    else {
        cout << 0;
    }


    return 0;
}