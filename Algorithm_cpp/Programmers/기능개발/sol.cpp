#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    int cur_max = 0;
    int cnt = 1;

    for (int i = 0; i < progresses.size(); i++) {
        int cur = 100 - progresses[i];

        // cout << " cur : " << cur << endl;
        int quotient = 0;
        if (cur % speeds[i] == 0) {
            quotient = (cur / speeds[i]);
        } else {
            quotient = (cur / speeds[i]) + 1;
        }

        cout << " cur_max : " << cur_max << " quotient : " << quotient << endl;

        if (quotient > cur_max) {
            cur_max = quotient;
            if (i != 0) {
                cout << " add " << endl;
                answer.push_back(cnt);
                cnt = 1;
            }

        } else {
            cnt++;
        }

        // cout << " quotient  : " << quotient << endl;
        cout << " cnt  : " << cnt << endl;
    }

    answer.push_back(cnt);

    return answer;
}