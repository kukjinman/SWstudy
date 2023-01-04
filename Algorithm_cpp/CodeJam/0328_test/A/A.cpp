#include <deque>
#include <iostream>

int T;
int n, L, F;

using namespace std;

deque<std::string> dq;

void solve()
{

    int pair_count = 0;

    for (int i = 0; i < n; i++) {
        string tmp = "";
        cin >> tmp;
        dq.push_back(tmp);
    }

    string s1 = "";
    string s2 = "";

    int loop_counter = 0;

    while (!dq.empty()) {

        if (loop_counter > dq.size()) {

            // cout << "dq.size() : " << dq.size() << endl;
            loop_counter = 0;
            dq.pop_front();
            // cout << "1 cycle is done" << endl;
        }

        if (!dq.empty()) {

            s1 = dq.front();
            dq.pop_front();
        }
        if (!dq.empty()) {

            s2 = dq.front();
            dq.pop_front();
        } else {
            break;
        }

//         cout << "s1 : " << s1 << endl;
//         cout << "s2 : " << s2 << endl;

        int count = 0;
        for (int z = 0; z < F; z++) {

            // cout << "s1 " << s1[L - z - 1] << " "
            //      << "s2 " << s2[L - z - 1] << endl;

            if (s1[L - z - 1] == s2[L - z - 1]) {
                count++;
                // cout << "count : " << count << endl;
            }
        }

        if (count >= F) {
            pair_count++;
            loop_counter = 0;
            // cout << "pair_count : " << pair_count << endl;
        } else {
            dq.push_front(s1);
            dq.push_back(s2);
        }

        loop_counter++;
    }

    cout << pair_count << endl;
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; i++) {

        cin >> n >> L >> F;
        solve();
    }

    return 0;
}
