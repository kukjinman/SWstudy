
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    priority_queue<int> pq_client;
    priority_queue<int> pq_host;

    cin >> n;

    for (int i = 0; i < n; i++) {

        int tmp;
        cin >> tmp;

        pq_client.push(tmp);
    }

    for (int i = 0; i < n; i++) {

        int tmp;
        cin >> tmp;

        pq_host.push(tmp);
    }

    // cout << " c top : " << pq_client.top() << endl;
    // cout << " h top : " << pq_host.top() << endl;
    int cnt = 0;

    while (!pq_client.empty()) {
        if (pq_client.top() < pq_host.top()) {
            cnt++;
            pq_client.pop();
            pq_host.pop();

        } else {

            pq_client.pop();
        }
    }

    if (cnt >= (n + 1) / 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}