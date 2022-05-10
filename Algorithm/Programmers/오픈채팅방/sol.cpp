#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer, state;

    map<string, string> userName_list;

    for (int i = 0; i < record.size(); i++) {
        string first = record[i].substr(0, record[i].find(" "));
        string remained = record[i].substr(record[i].find(" ") + 1);

        // cout << " f : " << first << " l : " << remained << endl;

        string second = remained.substr(0, remained.find(" "));
        string third = remained.substr(remained.find(" ") + 1);

        // cout << " f : " << first << " s : " << second << " t : " << third << endl;

        if (first == "Enter") {
            state.push_back("님이 들어왔습니다.");
            answer.push_back(second);

            userName_list[second] = third;
        } else if (first == "Leave") {
            state.push_back("님이 나갔습니다.");
            answer.push_back(second);

        } else {

            userName_list[second] = third;
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        answer[i] = userName_list[answer[i]] + state[i];
    }

    return answer;
}