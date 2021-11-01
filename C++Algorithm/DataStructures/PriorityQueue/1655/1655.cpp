#include <iostream>
#include <queue>

using namespace std;

#define mode2

#ifdef mode1

//This is the NlogN timeout code

template <typename T>
void print_ans(T q)
{ // NB: pass by value so the print uses a copy

    int midCounter = (q.size() + 1) / 2;
    // cout << " cnter : " << midCounter << endl;
    // cout << endl;

    int cnt = 0;
    while (!q.empty()) {
        cnt++;

        // cout << "cnt : " << cnt << " midCounter : " << midCounter << endl;
        if (cnt == midCounter) {
            std::cout << q.top() << "\n";
            break;
        }

        q.pop();
    }
}

template <typename T>
void print_queue(T q)
{ // NB: pass by value so the print uses a copy

    cout << "----------------------------" << endl;

    while (!q.empty()) {
        std::cout << "[p] " << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';

    cout << "----------------------------" << endl;
}

int main(int argc, char** argv)
{

    int N = 0;
    cin >> N;

    // auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, greater<int>> q;

    for (int i = 0; i < N; i++) {
        int buf = 0;
        cin >> buf;

        q.push(buf);
        print_ans(q);

        // print_queue(q);
    }

    return 0;
}

#endif

#ifdef mode2

template <typename T>
void print_queue(T q)
{ // NB: pass by value so the print uses a copy

    cout << "----------------------------" << endl;

    while (!q.empty()) {
        std::cout << "[p] " << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';

    cout << "----------------------------" << endl;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N = 0;
    cin >> N;

    // auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    // small is top
    std::priority_queue<int, std::vector<int>, greater<int>> top_q;

    // big is top
    std::priority_queue<int, std::vector<int>, less<int>> bottom_q;

    for (int i = 0; i < N; i++) {
        int buf = 0;
        cin >> buf;

        if (bottom_q.size() == 0 && top_q.size() == 0) {
            bottom_q.push(buf);
            cout << bottom_q.top() << '\n';
            continue;
        }

        if (bottom_q.size() > top_q.size()) {

            if (bottom_q.top() > buf) {

                int temp = bottom_q.top();
                bottom_q.pop();
                bottom_q.push(buf);
                top_q.push(temp);
            } else {
                top_q.push(buf);
            }

        } else {

            if (top_q.top() < buf) {
                int temp = top_q.top();
                top_q.pop();
                top_q.push(buf);
                bottom_q.push(temp);
            } else {
                bottom_q.push(buf);
            }
        }

        // cout << " ---------top-------------- " << endl;
        // print_queue(top_q);
        // cout << " ----------bottom------------ " << endl;
        // print_queue(bottom_q);

        cout << bottom_q.top() << '\n';
    }

    return 0;
}
#endif