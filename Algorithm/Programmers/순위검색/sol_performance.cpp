#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct s_info {
    string lan;
    string task;
    string level;
    string food;
    int score;

} S_INFO;

//result
// 테스트 1 〉	통과 (0.04ms, 4.16MB)
// 테스트 2 〉	통과 (0.05ms, 4.17MB)
// 테스트 3 〉	통과 (0.13ms, 4.15MB)
// 테스트 4 〉	통과 (1.10ms, 3.96MB)
// 테스트 5 〉	통과 (3.23ms, 4.06MB)
// 테스트 6 〉	통과 (7.19ms, 4.02MB)
// 테스트 7 〉	통과 (3.86ms, 4.44MB)
// 테스트 8 〉	통과 (15.04ms, 5.55MB)
// 테스트 9 〉	통과 (15.44ms, 5.54MB)
// 테스트 10 〉	통과 (16.41ms, 5.73MB)
// 테스트 11 〉	통과 (3.64ms, 4.17MB)
// 테스트 12 〉	통과 (7.19ms, 4.24MB)
// 테스트 13 〉	통과 (4.00ms, 4.3MB)
// 테스트 14 〉	통과 (14.10ms, 4.51MB)
// 테스트 15 〉	통과 (14.17ms, 4.5MB)
// 테스트 16 〉	통과 (3.18ms, 4.09MB)
// 테스트 17 〉	통과 (6.88ms, 4.17MB)
// 테스트 18 〉	통과 (13.96ms, 4.39MB)

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;

    vector<S_INFO> st_info;

    for (int i = 0; i < info.size(); i++) {

        S_INFO tmp;

        string t1 = info[i].substr(0, info[i].find(" "));
        string next = info[i].substr(info[i].find(" ") + 1);
        string t2 = next.substr(0, next.find(" "));
        string next2 = next.substr(next.find(" ") + 1);

        string t3 = next2.substr(0, next2.find(" "));
        string next3 = next2.substr(next2.find(" ") + 1);

        string t4 = next3.substr(0, next3.find(" "));
        string next4 = next3.substr(next3.find(" ") + 1);

        tmp.lan = t1;
        tmp.task = t2;
        tmp.level = t3;
        tmp.food = t4;
        tmp.score = stoi(next4);

        st_info.push_back(tmp);
        // cout << " t1 : " << t1 << " t2 : " << t2 << " t3 : " << t3 << " t4 : " << t4 << " scr : " << tmp.score << endl;
    }

    for (int i = 0; i < query.size(); i++) {

        S_INFO tmp;
        string t1 = "";
        string next = "";

        if (query[i][0] == '-') {
            t1 = "none";
            next = query[i].substr(query[i].find(" ") + 5);

        } else {
            t1 = query[i].substr(0, query[i].find(" "));
            next = query[i].substr(query[i].find(" ") + 5);
        }

        string t2 = "";
        string next2 = "";
        if (next[0] == '-') {
            t2 = "none";
            next2 = next.substr(next.find(" ") + 5);

        } else {
            t2 = next.substr(0, next.find(" "));
            next2 = next.substr(next.find(" ") + 5);
        }

        string t3 = "";
        string next3 = "";
        if (next2[0] == '-') {
            t3 = "none";
            next3 = next2.substr(next2.find(" ") + 5);

        } else {
            t3 = next2.substr(0, next2.find(" "));
            next3 = next2.substr(next2.find(" ") + 5);
        }

        string t4 = "";
        string next4 = "";
        if (next3[0] == '-') {
            t4 = "none";
            next4 = next3.substr(next3.find(" ") + 1);

        } else {
            t4 = next3.substr(0, next3.find(" "));
            next4 = next3.substr(next3.find(" ") + 1);
        }

        tmp.lan = t1;
        tmp.task = t2;
        tmp.level = t3;
        tmp.food = t4;
        tmp.score = stoi(next4);

        // cout << " t1 : " << t1 << " t2 : " << t2 << " t3 : " << t3 << " t4 : " << t4 << " scr : " << tmp.score << endl;

        int cnt = 0;
        for (int j = 0; j < st_info.size(); j++) {
            if (tmp.lan == "none") {

            } else {

                if (st_info[j].lan == tmp.lan) {

                } else {
                    continue;
                }
            }

            if (tmp.task == "none") {

            } else {
                if (st_info[j].task == tmp.task) {

                } else {
                    continue;
                }
            }

            if (tmp.level == "none") {

            } else {

                if (st_info[j].level == tmp.level) {

                } else {
                    continue;
                }
            }

            if (tmp.food == "none") {

            } else {
                if (st_info[j].food == tmp.food) {

                } else {
                    continue;
                }
            }

            if (st_info[j].score >= tmp.score) {
                cnt++;
            } else {

                continue;
            }
        }

        answer.push_back(cnt);
    }

    return answer;
}