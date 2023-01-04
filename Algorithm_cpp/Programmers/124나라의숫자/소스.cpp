#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";

    int num[3] = { 4,1,2 };


    while (n > 0)
    {
        string cur = to_string(num[(n % 3)]);
        // cout << "cur : " << cur << endl;

        if (n % 3 == 0)
        {
            n = n / 3 - 1;

        }
        else
        {
            n /= 3;

        }


        answer += cur;


    }

    reverse(answer.begin(), answer.end());

    return answer;
}