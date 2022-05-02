#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n;

#define MAX 10002

priority_queue<int> pq[MAX];

void printer()
{

    cout << "---------------" << endl;

    int idx = MAX;

    while (idx > 0) {

        while (!pq[idx].empty()) {
            int val = pq[idx].top();
            pq[idx].pop();

            cout << "idx : " << idx << " val : " << val << endl;
        }

        idx--;
    }
}

void input()
{

    cin >> n;

    for (int i = 0; i < n; i++) {

        int day = 0;
        int val = 0;
        cin >> val >> day;

        pq[day].push(val);
    }

    // printer();
}

void solve()
{
    int res = 0;

    int idx = MAX;
    int cnt = 1;
    bool first_visit = true;

    while (idx > 0) {

        // cout << "idx : " << idx << endl;

        while (!pq[idx].empty()) {

            cout << "idx : " << idx << endl;

            int cur_val = pq[idx].top();

            if (idx - cnt < 0) {
                break;
            }

            if (pq[idx - cnt].empty()) {

                cout << "add s1 : " << cur_val << endl;
                res += cur_val;
                pq[idx].pop();
                cnt++;
            } else {
                cout << " cnt " << cnt << endl;

                int next_val = pq[idx - cnt].top();
                if (cur_val > next_val) {

                    cout << "add s2 : " << cur_val << endl;
                    res += cur_val;
                    pq[idx].pop();

                } else {
                    if (first_visit == true) {
                        cout << "add s3 : " << cur_val << endl;

                        res += cur_val;
                        pq[idx].pop();
                    }

                    cnt = 1;
                    break;
                }
            }

            first_visit = false;
        }

        first_visit = true;
        cnt = 1;
        idx--;
    }
    // printer();
    cout << res << endl;
}

int main(int argc, char* argv[])
{

    input();
    solve();

    return 0;
}