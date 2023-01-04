#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0;

    string table[11] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = 0; i < 10; i++) {
        // cout << " t : " << table[i] << endl;
        // overload 이슈? 머냐 이거.. ㅂㄷㅂㄷ
        // s.replace(s.find(table[i]),table[i].size(),char(i));
        while (s.find(table[i]) != std::string::npos) {
            if (s.find(table[i]) == std::string::npos) {

            } else {

                string prev = s.substr(0, s.find(table[i]));
                string next = s.substr(s.find(table[i]) + table[i].size());
                // cout << " prev : " << prev << " next : " << next << endl;

                string cur = "";
                // cout << " test :  "<< char(i + 48) << endl;
                cur += prev;
                cur += char(i + 48);
                cur += next;

                s = cur;
            }
            // cout << " s: " << s << endl;
        }
    }
    answer = stoi(s);

    return answer;
}