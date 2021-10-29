#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

void copy_deque(const deque<int> src, deque<int>& dst)
{
    deque<int> dq_buf;
    dq_buf.resize(src.size());
    copy(src.begin(), src.end(), dq_buf.begin());

    // cout << "check dq_buf size : " << dq_buf.size() << endl;

    for (int i = 0; i < src.size(); i++) {
        dst.push_back(dq_buf.front());
        dq_buf.pop_front();
    }

    // cout << "check dst size : " << dst.size() << endl;
}

int main(int argc, char** argv)
{

    int N, M;
    cin >> N >> M;
    int arr[50];

    int sum_cnt = 0;

    deque<int> dq;
    queue<int> pick_item_q;

    for (int i = 1; i <= N; i++) {

        dq.push_back(i);
    }

    deque<int> right_dq;

    for (int i = 0; i < M; i++) {

        cin >> arr[i];
        pick_item_q.push(arr[i]);
    }

    while (!pick_item_q.empty()) {

        int cur_i = pick_item_q.front();
        // cout << "[0] cur_i : " << cur_i << " dq.front : " << dq.front() << endl;

        pick_item_q.pop();

        if (cur_i == dq.front()) {

            // cout << " dq front : " << dq.front() << endl;
            dq.pop_front();

        } else {

            // Checking Left
            deque<int> left_dq;

            copy_deque(dq, left_dq);

            int left_front = -1;
            int left_cnt = 0;
            while (1) {

                // cout << "left dq size : " << left_dq.size() << endl;

                left_front = left_dq.front();
                left_dq.pop_front();
                left_dq.push_back(left_front);
                left_cnt++;

                if (left_dq.front() == cur_i) {

                    // cout << "[left] cur_i found -- dq front : " << left_dq.front() << " cur : " << cur_i << endl;
                    // cout << "left_cnt : " << left_cnt << endl;
                    left_dq.pop_front();
                    break;
                }
            }

            // Checking Right
            deque<int> right_dq;
            copy_deque(dq, right_dq);

            int right_front = -1;
            int right_cnt = 0;
            while (1) {

                // cout << "right dq size : " << right_dq.size() << endl;

                right_front = right_dq.back();
                right_dq.pop_back();
                right_dq.push_front(right_front);
                right_cnt++;

                if (right_dq.front() == cur_i) {

                    // cout << "[right] cur_i found -- dq front : " << right_dq.front() << " cur : " << cur_i << endl;
                    right_dq.pop_front();
                    break;
                }
            }

            // cout << "left_cnt : " << left_cnt << " right_cnt : " << right_cnt << endl;

            dq.clear();

            if (right_cnt > left_cnt) {
                copy_deque(left_dq, dq);

                sum_cnt += left_cnt;
                // cout << "sum_cnt left copy : " << sum_cnt << endl;
            } else {
                copy_deque(right_dq, dq);

                sum_cnt += right_cnt;
                // cout << "sum_cnt right copy : " << sum_cnt << endl;
            }
        }
    }

    cout << sum_cnt << endl;

    return 0;
}