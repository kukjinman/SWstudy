#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<float, int> a, pair<float, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    map<int, int> m;
    vector<pair<float, int>> pass_percent;

    int total = stages.size();

    for (int i : stages) {
        m[i]++;
    }

    for (int i = 1; i <= N; i++) {

        if (m[i] != 0) {

            pass_percent.push_back(make_pair(float(m[i]) / float(total), i));
        } else {
            pass_percent.push_back(make_pair(0, i));
        }
        total -= m[i];
        // cout << " total : " << total << endl;
    }

    sort(pass_percent.begin(), pass_percent.end(), cmp);

    for (int i = 0; i < pass_percent.size(); i++) {
        // cout << " f : " << pass_percent[i].first << " s : " << pass_percent[i].second << endl;
        answer.push_back(pass_percent[i].second);
    }

    return answer;
}