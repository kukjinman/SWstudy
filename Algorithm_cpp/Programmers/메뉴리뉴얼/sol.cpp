#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> mp_order;

void dfs(int cnt, int level, int n_, string str_, string buf)
{
    string tmp = buf;

    if (level == n_) {

        sort(tmp.begin(), tmp.end());
        mp_order[tmp]++;
        // cout << " tmp : " << tmp << endl;
        return;
    }

    for (int i = cnt; i < str_.size(); i++) {

        tmp += str_[i];
        // cout << " letter : " << str_[i] << endl;
        dfs(i + 1, level + 1, n_, str_, tmp);
        tmp = buf;
    }

    return;
}

bool cmp(pair<string, int> a, pair<string, int> b)
{

    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int n : course) {

        for (int i = 0; i < orders.size(); i++) {
            cout << " s : " << orders[i] << endl;
            dfs(0, 0, n, orders[i], "");
        }

        vector<pair<string, int>> v(mp_order.begin(), mp_order.end());
        sort(v.begin(), v.end(), cmp);

        int cur_max = v[0].second;
        for (int i = 0; i < v.size(); i++) {

            if (v[i].second < 2) {
                break;
            }

            // cout << " first : " << v[i].first << " second : " << v[i].second << endl;
            if (cur_max != v[i].second) {
                break;
            }
            answer.push_back(v[i].first);
        }
        mp_order.clear();
    }

    sort(answer.begin(), answer.end());

    return answer;
}