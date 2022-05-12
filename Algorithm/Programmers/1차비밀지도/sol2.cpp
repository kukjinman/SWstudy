#include <iostream>
#include <string>
#include <vector>

using namespace std;

int* toBinary(int n_, int num)
{
    int ret[17] = {
        0,
    };
    int num_ = num;
    int cnt = 0;

    cout << " num : " << num << endl;

    while (num_) {
        int cur = num_ % 2;
        num_ /= 2;

        ret[cnt] = cur;
        cnt++;
    }

    for (int i = 0; i < n_; i++) {
        cout << ret[i] << " ";
    }

    cout << endl;
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    toBinary(n, arr1[0]);

    return answer;
}