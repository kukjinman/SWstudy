#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> map_, vector<vector<int>> q_)
{

    for (int i = 0; i < q_.size(); i++) {
        int s_r = q_[i][0];
        int s_c = q_[i][1];
        int e_r = q_[i][2];
        int e_c = q_[i][3];

        // cout << " " << s_r << " " << s_c << " " << e_r << " " << e_c << endl;

        int temp = map_[s_r - 1][s_c - 1];
        // This need to fix and start
        for (int i = s_c; i < e_c; i++) {

            temp = map_[s_r - 1][i];
            cout << " temp : " << temp << endl;
            map_[s_r - 1][i] = temp;
        }

        // cout << map_.size() << endl;

        for (int i = 0; i < map_[0].size(); i++) {
            for (int j = 0; j < map_.size(); j++) {
                cout << map_[i][j];
            }
            cout << endl;
        }

        // for (int i = 0; i < e_r - s_r; i++) {
        // }
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> map(rows);

    int cnt = 0;
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

    rotate(map, queries);

    return answer;
}