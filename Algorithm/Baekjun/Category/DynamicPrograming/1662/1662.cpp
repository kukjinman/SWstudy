#include <iostream>
#include <string>

using namespace std;

string s;

int index = 0;
int recurse()
{
    int cnt = 0;

    // cout << "index = " << index <<  " cnt : " << cnt << endl;

    while (index < s.size())
    {
        if (s.at(index) == '(')
        {


            int num = s.at(index - 1) - '0';
            // cout << "num : " << num << endl;

            cnt--;
            index++;
            int res_cnt = recurse();
            // cout << " res_cnt : " << res_cnt << endl;
            cnt += res_cnt * num;

            // cout << " tmp : " << tmp << endl;

        }
        else if (s.at(index) == ')')
        {
            return cnt;
        }
        else
        {
            cnt++;
        }
        index++;
        // cout << " index ||||||||||||||||||| " << index << endl; 
    }


    return cnt;

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    int ans = recurse();
    cout << ans << endl;
    return 0;
}
