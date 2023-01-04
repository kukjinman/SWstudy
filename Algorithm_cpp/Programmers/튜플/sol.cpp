#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{

    return a.second > b.second;
}

vector<int> solution(string s)
{
    vector<int> answer;
    unordered_map<string, int> mp;

    string tmp = "";
    bool num_flag = false;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '{') {

            num_flag = true;
        } else {

            if (s[i] == '}' && i != s.size() - 1) {
                // cout << " tmp : " << tmp << endl;
                mp[tmp]++;
                tmp = "";
                num_flag = false;
            }

            if (num_flag) {

                if (s[i] == ',') {
                    // cout << " tmp : " << tmp << endl;
                    mp[tmp]++;
                    tmp = "";
                } else {
                    //number
                    tmp += s[i];
                }
            }
        }
    }

    vector<pair<string, int>> v(mp.begin(), mp.end());

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {

        answer.push_back(stoi(v[i].first));
        // cout << " n : " << v[i].first << " ";
    }

    return answer;
}