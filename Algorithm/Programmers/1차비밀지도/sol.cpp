#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int* toBinary(int n_, int num)
{
    int ret[17] = {
        0,
    };

    for (int i = n_ - 1; i >= 0; i--) {

        ret[n_ - 1 - i] = num >> i & 1;
    }

    // for (int i = 0; i < n_; i++) {
    //     cout << ret[i] << " ";
    // }

    // cout << endl;
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    int map1[17][17] = {
        0,
    };

    int map2[17][17] = {
        0,
    };

    for (int i = 0; i < arr1.size(); i++) {
        memcpy(map1[i], toBinary(n, arr1[i]), sizeof(map1[i]));
    }

    for (int i = 0; i < arr2.size(); i++) {
        memcpy(map2[i], toBinary(n, arr2[i]), sizeof(map2[i]));
    }

    for (int i = 0; i < n; i++) {

        string tmp;

        for (int j = 0; j < n; j++) {

            if ((map1[i][j] | map2[i][j]) == 1) {
                tmp += "#";
            } else {
                tmp += " ";
            }

            cout << char((map1[i][j] | map2[i][j]) + 48) << " ";
        }

        answer.push_back(tmp);

        cout << endl;
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << map1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << " -------------------" << endl;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << map2[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return answer;
}