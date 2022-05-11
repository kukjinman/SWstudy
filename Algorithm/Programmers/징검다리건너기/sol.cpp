#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

bool Can_Cross(vector<int>& v__, int k__)
{

    int jump_cnt = 1;

    for (int i = 0; i < v__.size(); i++) {

        if (v__[i] == 0) {
            if (jump_cnt >= k__) {
                // cout << " jump fail " << i << endl;
                return false;
            } else {
                // cout << " jump " << jump_cnt << endl;

                jump_cnt++;
            }

        } else {
            jump_cnt = 1;
            v__[i]--;
        }
    }

    return true;
}

int run_Friends(vector<int>& v_, int k_)
{

    int crossed_friends = 0;

    int min = INT_MAX;

    min = *min_element(v_.begin(), v_.end());

    crossed_friends += min;
    cout << "c : " << crossed_friends << endl;

    for (int i = 0; i < v_.size(); i++) {

        if (v_[i] == 0) {

        } else {

            if (v_[i] - min < 0) {
                v_[i] = 0;
            } else
                v_[i] -= min;
        }
    }

    while (1) {

        for (int i = 0; i < v_.size(); i++) {
            // cout << v_[i] << " ";
        }
        // cout << endl;

        if (Can_Cross(v_, k_)) {
            crossed_friends++;
        } else {
            break;
        }
    }

    return crossed_friends;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;

    answer = run_Friends(stones, k);

    return answer;
}