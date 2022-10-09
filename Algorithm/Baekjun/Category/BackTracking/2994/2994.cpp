#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num;

// next_permutation 사용하지 않고 푸는 코드도 올리도록 하자.

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> num;

    // cout << num<< endl;
    bool chk = next_permutation(num.begin(), num.end());

    if (chk)
        cout << num << endl;
    else
        cout << '0';


    return 0;
}