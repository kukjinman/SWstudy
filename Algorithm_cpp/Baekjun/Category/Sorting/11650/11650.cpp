#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

deque<pair<int, int>> dq;

bool comp(pair<int, int> a, pair<int, int> b)
{
    // cout << "---------------------" << endl;
    // cout << " a : " << a << " b : " << b << endl;

    if (a.first != b.first) {

        return a.first < b.first;
    } else {

        if (a.second == b.second) {
            return true;
        } else {
            return a.second < b.second;
        }
    }
}

int main(int argc, char* argv[])
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int first = 0;
        int second = 0;

        cin >> first >> second;

        dq.push_back(make_pair(first, second));
    }

    // cout << " ------------------ " << endl;
    sort(dq.begin(), dq.end(), comp);

    while (!dq.empty()) {
        //endl << this takes long time and cause timeout
        cout << dq.front().first << " " << dq.front().second << '\n';
        dq.pop_front();
    }

    return 0;
}
