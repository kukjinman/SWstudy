#include <iostream>
#include <vector>

using namespace std;

int n;

vector<pair<int, int>> v;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int first, second;

        cin >> first >> second;
        v.push_back(make_pair(first, second));

    }

    for (auto iter = v.begin(); iter != v.end(); iter++) {
        int count = n;
        int x = iter->first;
        int y = iter->second;

        for (auto it_ = v.begin(); it_ != v.end(); it_++)
        {

            if(iter == it_)
            {
                continue;
            }

            int x_ = it_->first;
            int y_ = it_->second;
            
            if(x >= x_ && y >= y_)
            {
                count--;
            }
            else if( x >= x_ || y>= y_)
            {
                count--;
            }



        }

        cout << count << " ";

    }
}
