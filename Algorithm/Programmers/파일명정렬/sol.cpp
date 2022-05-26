#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//구조 : 파일 이름(index, head, number)
struct fileName {
    int index;
    string head;
    int number;
};

vector<fileName> v;

bool cmp(const fileName a, const fileName b)
{
    if (a.head == b.head) {
        if (a.number == b.number) {
            return a.index < b.index;
        } else {
            return a.number < b.number;
        }

    } else {
        return a.head < b.head;
    }
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;

    fileName f_item;

    // 0:head, 1: num , 2:tail
    int pos = 0;

    int counter = 0;
    for (string s : files) {

        string tmp = "";

        string s_lower = "";
        for (int j = 0; j < s.length(); j++) {
            s_lower += tolower(s[j]);
        }

        for (char c : s_lower) {

            // cout << " c :  " << c << " int c : " << int(c) << endl;
            if (pos == 0) {
                if (c >= '0' && int(c) <= '9') {
                    f_item.head = tmp;
                    tmp = "";
                    tmp += c;
                    pos++;

                    // cout << " f_item.head : " << f_item.head << endl;
                    continue;
                }
                tmp += c;
            } else if (pos == 1) {

                if (tmp.size() >= 5) {
                    // cout << " num size is over 5" << endl;
                    f_item.number = stoi(tmp);
                    tmp = "";
                    tmp += c;
                    pos++;
                    continue;
                    // cout << " f_item.number : " << f_item.number << endl;
                } else if (c < '0' || c > '9') {
                    f_item.number = stoi(tmp);
                    tmp = "";
                    tmp += c;
                    pos++;
                    // cout << " f_item.number : " << f_item.number << endl;
                    continue;
                }
                tmp += c;

            } else {
            }
        }

        pos = 0;
        f_item.index = counter;

        v.push_back(f_item);

        counter++;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {

        answer.push_back(files[v[i].index]);
    }

    return answer;
}