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

// 테스트 1 〉	통과 (0.06ms, 4.09MB)
// 테스트 2 〉	통과 (0.06ms, 3.64MB)
// 테스트 3 〉	통과 (0.47ms, 3.57MB)
// 테스트 4 〉	통과 (4.24ms, 4.09MB)
// 테스트 5 〉	통과 (23.44ms, 4.17MB)
// 테스트 6 〉	통과 (52.46ms, 4.13MB)
// 테스트 7 〉	통과 (20.58ms, 4.23MB)
// 테스트 8 〉	통과 (95.73ms, 4.44MB)
// 테스트 9 〉	통과 (98.33ms, 4.31MB)
// 테스트 10 〉	통과 (100.63ms, 4.38MB)
// 테스트 11 〉	통과 (20.58ms, 4.17MB)
// 테스트 12 〉	통과 (50.51ms, 4.09MB)
// 테스트 13 〉	통과 (20.74ms, 4.26MB)
// 테스트 14 〉	통과 (99.10ms, 4.17MB)
// 테스트 15 〉	통과 (100.17ms, 4.17MB)
// 테스트 16 〉	통과 (19.36ms, 4.17MB)
// 테스트 17 〉	통과 (51.50ms, 3.92MB)
// 테스트 18 〉	통과 (99.55ms, 4.16MB)

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;


    //O(mn) 이라 실패
    // answer.cpp는 O(n) + O(m) 번 수행 10만개 이상에서 효율적임.
     

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
        for (int j = 0; j < info.size(); j++) {

            string s1 = info[j].substr(0, info[j].find(" "));
            string info_next = info[j].substr(info[j].find(" ") + 1);
            string s2 = info_next.substr(0, info_next.find(" "));
            string info_next2 = info_next.substr(info_next.find(" ") + 1);

            string s3 = info_next2.substr(0, info_next2.find(" "));
            string info_next3 = info_next2.substr(info_next2.find(" ") + 1);

            string s4 = info_next3.substr(0, info_next3.find(" "));
            string info_next4 = info_next3.substr(info_next3.find(" ") + 1);

            // cout << " s1 : " << s1 << " s2 : " << s2 << " s3 : " << s3 << " s4 : " << s4 << " scr : " << stoi(info_next4) << endl;

            if (tmp.lan == "none") {

            } else {

                if (s1 == tmp.lan) {

                } else {
                    continue;
                }
            }

            if (tmp.task == "none") {

            } else {
                if (s2 == tmp.task) {

                } else {
                    continue;
                }
            }

            if (tmp.level == "none") {

            } else {

                if (s3 == tmp.level) {

                } else {
                    continue;
                }
            }

            if (tmp.food == "none") {

            } else {
                if (s4 == tmp.food) {

                } else {
                    continue;
                }
            }

            if (stoi(info_next4) >= tmp.score) {
                cnt++;
            } else {

                continue;
            }
        }

        answer.push_back(cnt);
    }

    return answer;
}