#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;

    int cnt = 0;
    int z_cnt = 0;

    for (int i = 0; i < lottos.size(); i++) {
        int cur = lottos[i];
        cout << " cur : " << cur << endl;

        if (cur == 0) {
            z_cnt++;
            continue;
        }

        if (find(win_nums.begin(), win_nums.end(), cur) == win_nums.end()) {
            cout << " not in the list" << endl;
        } else {
            cout << " found " << endl;
            cnt++;
        }
    }

    int max = cnt + z_cnt;
    int min = cnt;

    int rank_max = 7 - max;
    int rank_min = 7 - min;
    if (rank_min >= 6) {
        rank_min = 6;
    }
    if (rank_max >= 6) {
        rank_max = 6;
    }

    answer.push_back(rank_max);
    answer.push_back(rank_min);

    return answer;
}