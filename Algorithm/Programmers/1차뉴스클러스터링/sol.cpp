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

    return answer;
}