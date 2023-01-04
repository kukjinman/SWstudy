#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b)
    {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;

    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    // for (int i = 0; i < jobs.size(); i++) {
    //     cout << " : " << jobs[i][0] << " " << jobs[i][1] << endl;
    // }

    int cnt = 0;
    int cur = 0;

    while (cnt < jobs.size() || !pq.empty()) {

        if (cnt < jobs.size() && cur >= jobs[cnt][0]) {
            pq.push(jobs[cnt]);
        }

        if (!pq.empty()) {
            cur += jobs[cnt][1];

        } else {
            //아무것도 없을시 제일 처음 돌아가는 코드
            cur += jobs[cnt][0];
        }
    }

    return answer;
}