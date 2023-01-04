#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    vector<int> width;
    vector<int> length;

    for (auto v : sizes) {

        int first = 0;
        int second = 0;

        if (v[0] >= v[1]) {

            width.push_back(v[0]);
            length.push_back(v[1]);

        } else {

            width.push_back(v[1]);
            length.push_back(v[0]);
        }
    }

    sort(width.begin(), width.end(), greater<int>());
    sort(length.begin(), length.end(), greater<int>());

    // cout << "w : " << width[0] << " l :" << length[0] << endl;

    answer = width[0] * length[0];

    return answer;
}