#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num;

// next_permutation ������� �ʰ� Ǫ�� �ڵ嵵 �ø����� ����.

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