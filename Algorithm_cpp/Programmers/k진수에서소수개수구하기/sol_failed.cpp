#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

bool PrimeChecker(string s_)
{
    //소수 체크 코드는 외울 것
    int ret = false;

    if (s_.empty() || s_ == "1")
        return false;

    long long num = stol(s_);

    for (long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    ret = true;
    return ret;
}

int solution(int n, int k)
{
    int answer = 0;
    int cur = n;
    string s;

    if (k == 0) {
        return answer;
    }

    while (cur > 0) {
        // int tmp = cur % k;
        // cout << "tmp :" << tmp << endl;

        s += to_string(cur % k);
        // cout << " cur : " << cur << endl;
        cur = cur / k;
        // cout << " cur : " << cur << endl;
    }

    reverse(s.begin(), s.end());

    string buf = "";

    // for (int i = 0; i < s.size(); i++) {

    //     if (s[i] == '0') {
    //         if (!buf.empty()) {

    //             if (PrimeChecker(buf)) {
    //                 answer++;
    //             }

    //             buf = "";
    //             continue;
    //         }
    //     }
    //     buf += s[i];
    // }

    for (char c : s) {

        if (c == '0') {

            if (!buf.empty() && PrimeChecker(buf)) {
                answer++;
            }

            buf = "";
            continue;
        }
        buf += c;
    }

    // 여기 buf.empty() 확인 안할때 test 12에서 fail남
    if (!buf.empty() && PrimeChecker(buf)) {
        answer++;
    }

    return answer;
}