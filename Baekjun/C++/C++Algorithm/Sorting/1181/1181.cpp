#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

deque<string> dq;

bool comp(string a, string b)
{
    // cout << "---------------------" << endl;
    // cout << " a : " << a << " b : " << b << endl;

    if (a.size() > b.size()) {
        // cout << " stage 1" << endl;
        return false;
    } else if (a.size() < b.size()) {
        return true;
    } else {

        if (a < b) {

            // cout << " stage 2" << endl;
            return true;

        } else {
            // cout << " stage 3" << endl;
            return false;
        }
    }
}

int main(int argc, char* argv[])
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string buf = "";
        cin >> buf;
        dq.push_back(buf);
    }

    // cout << " ------------------ " << endl;
    sort(dq.begin(), dq.end(), comp);

    string buf = "";
    if (!dq.empty()) {

        buf = dq.front();
        cout << dq.front() << endl;
        dq.pop_front();
    }

    while (!dq.empty()) {

        if (buf == dq.front()) {
            dq.pop_front();
        } else {
            cout << dq.front() << endl;
            buf = dq.front();
            dq.pop_front();
        }
    }

    return 0;
}