#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;

    // set을 pair로 사용 불가 map처럼 map[index] 키를 사용하여 value를 구할 수 없음.
    // 중복 제거용 set container
    // 1st string : 신고자
    // 2nd string : 신고 당한 사람
    // set<pair<string,string>> r_list;

    //유저별 신고자 list
    map<string, set<string>> user_list;

    //신고된 횟수 list
    map<string, int> report_list;

    // 중복 제거 작업
    for (int i = 0; i < report.size(); i++) {
        // cout << report[i] << endl;

        //         cout << report[i].substr(0,report[i].find(" ")) << endl;
        //         cout << report[i].substr(report[i].find(" ")+1) << endl;

        string from = report[i].substr(0, report[i].find(" "));
        string to = report[i].substr(report[i].find(" ") + 1);

        if (user_list[from].find(to) == user_list[from].end()) {

            // cout << " from : " << from << " to : " << to << endl;
            report_list[to]++;
            user_list[from].insert(to);

        } else {
            // cout << "[dup] from : " << from << " to : " << to << endl;
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        int temp = 0;

        for (auto s : user_list[id_list[i]]) {
            // cout <<" user : " << id_list[i] << " target : " << s << endl;
            if (report_list[s] >= k)
                temp++;
        }

        answer.push_back(temp);
    }

    for (auto i : answer) {
        // cout << i << " ";
    }

    // cout << endl;

    return answer;
}