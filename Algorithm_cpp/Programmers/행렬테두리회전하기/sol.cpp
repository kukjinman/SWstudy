#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> map_, vector<vector<int>> q_, vector<int>& out_)
{

    for (int i = 0; i < q_.size(); i++) {

        priority_queue<int, vector<int>, greater<int>> pq;

        int s_r = q_[i][0];
        int s_c = q_[i][1];
        int e_r = q_[i][2];
        int e_c = q_[i][3];

        // cout << " " << s_r << " " << s_c << " " << e_r << " " << e_c << endl;

        int temp = 0;
        int cur = map_[s_r - 1][s_c - 1];

        // dir right
        for (int i = s_c - 1; i < e_c - 1; i++) {

            temp = map_[s_r - 1][i + 1];
            // cout << " temp : " << temp << endl;
            map_[s_r - 1][i + 1] = cur;
            pq.push(cur);

            cur = temp;
        }

        // dir down
        for (int i = s_r - 1; i < e_r - 1; i++) {

            temp = map_[i + 1][e_c - 1];
            // cout << " temp : " << temp << endl;
            map_[i + 1][e_c - 1] = cur;
            pq.push(cur);

            cur = temp;
        }

        // dir left
        for (int i = e_c - 1; i > s_c - 1; i--) {

            temp = map_[e_r - 1][i - 1];
            // cout << " temp : " << temp << endl;
            map_[e_r - 1][i - 1] = cur;
            pq.push(cur);

            cur = temp;
        }

        // dir up
        for (int i = e_r - 1; i > s_r - 1; i--) {

            temp = map_[i - 1][s_c - 1];
            // cout << " temp : " << temp << endl;
            map_[i - 1][s_c - 1] = cur;
            pq.push(cur);

            cur = temp;
        }

        out_.push_back(pq.top());
        // cout << " pq top  : " << pq.top() << endl;

        // for (int i = 0; i < map_[0].size(); i++) {
        //     for (int j = 0; j < map_.size(); j++) {
        //         cout << map_[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // for (int i = 0; i < e_r - s_r; i++) {
        // }
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> map(rows);

    int cnt = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i].push_back(cnt);
            cnt++;
        }
    }

    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < columns; j++) {
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }

    rotate(map, queries, answer);

    return answer;
}