#include <iostream>
#include <map>
#include <string>

using namespace std;

//aa1+aa2	AAAA12	43690
//예제 설명
// str1 aa aa    str2 aa aa aa로
// 교집합 aa aa    합집합 aa aa aa 로 2/3 => 43690/65536 값이 나온다.

int solution(string str1, string str2)
{
    int answer = 0;

    string str1_low = "";
    string str2_low = "";

    map<string, int> mp1;
    map<string, int> mp2;

    for (int i = 0; i < str1.size(); i++) {
        str1_low += tolower(str1[i]);
    }

    // cout << " str1_low : " << str1_low << endl;

    for (int i = 0; i < str2.size(); i++) {
        str2_low += tolower(str2[i]);
    }

    // cout << " str2_low : " << str2_low << endl;

    for (int i = 1; i < str1_low.size(); i++) {

        // cout << "[str1] 1 : " << str1_low[i - 1] << " 2 : " << str1_low[i] << endl;

        if (str1_low[i - 1] >= 'a' && str1_low[i - 1] <= 'z' && str1_low[i] >= 'a' && str1_low[i] <= 'z') {
            string tmp = "";
            tmp += str1_low[i - 1];
            tmp += str1_low[i];
            mp1[tmp]++;

            // cout << "tmp1 : " << tmp << endl;

        } else {
        }
    }

    for (int i = 1; i < str2_low.size(); i++) {

        // cout << " 1 : " << str2_low[i - 1] << " 2 : " << str2_low[i] << endl;

        if (str2_low[i - 1] >= 'a' && str2_low[i - 1] <= 'z' && str2_low[i] >= 'a' && str2_low[i] <= 'z') {
            string tmp = "";
            tmp += str2_low[i - 1];
            tmp += str2_low[i];
            mp2[tmp]++;

            // cout << "tmp2 : " << tmp << endl;

        } else {
        }
    }

    int intersec_cnt = 0;
    int union_cnt = 0;

    int mp1_sum = 0;
    int mp2_sum = 0;

    //교집합
    for (auto it : mp1) {
        // cout << " first : " << it.first << " second : " << it.second << endl;

        if (mp2[it.first] >= 1) {

            if (mp1[it.first] > mp2[it.first])
                intersec_cnt += mp2[it.first];
            else {
                intersec_cnt += mp1[it.first];
            }
        }

        mp1_sum += it.second;
    }

    for (auto it : mp2) {
        // cout << " first : " << it.first << " second : " << it.second << endl;

        mp2_sum += it.second;
    }

    // cout << " mp1 : " << mp1.size() << " mp2 : " << mp2.size() << endl;
    // cout << " mp1_sum  : " << mp1_sum << " mp2_sum : " << mp2_sum << endl;

    if (mp1.size() + mp2.size() == 0) {
        if (str1_low == str2_low) {
            answer = 65536;
            return answer;
        }
    }

    if ((intersec_cnt + mp1_sum + mp2_sum) != 0) {
        double tmp = 0;
        tmp = (double)intersec_cnt / (double(mp1_sum + mp2_sum - intersec_cnt));
        answer = tmp * 65536;
    }
    return answer;
}