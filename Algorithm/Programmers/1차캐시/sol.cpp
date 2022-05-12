#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    for (int i = 0; i < cities.size(); i++)
        for (int j = 0; j < cities[i].length(); j++)
            cities[i][j] = tolower(cities[i][j]);

    vector<string> cities_list;

    // for (auto s : cities) {
    //     cout << s << " ";
    // }
    // cout << endl;

    for (int i = 0; i < cities.size(); i++) {

        auto it = find(cities_list.begin(), cities_list.end(), cities[i]);

        // for (auto s : cities_list) {
        //     // cout << "[]" << s << " ";
        // }
        // cout << endl;

        if (it == cities_list.end()) {
            // cout << " not found " << endl;
            answer += 5;

            if (cacheSize == 0)
                continue;
            else if (cities_list.size() > cacheSize) {
                cities_list.erase(cities_list.begin());
                cities_list.push_back(cities[i]);

            } else {
                cities_list.push_back(cities[i]);
            }

        } else {
            // cout << " cur : " << *it << endl;
            answer += 1;
            cities_list.erase(it);
            cities_list.push_back(cities[i]);
        }
    }

    return answer;
}