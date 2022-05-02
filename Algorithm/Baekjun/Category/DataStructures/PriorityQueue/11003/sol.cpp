#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct A {
    int data;
    int pos;
};

struct cmp { // 힙정렬(우선순위큐)를 위한 비교 함수 (A 구조체를 만들어주어서 따로 비교함수 만들어주는게 필요했다.)
    bool operator()(const A& a, const A& b)
    {
        return a.data > b.data; // min heap 이 되게끔, 즉 최소값이 루트에 오게끔
    }
};

int main()
{
    /* cin, cout 입출력 속도 향상 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    priority_queue<A, vector<A>, cmp> pq;
    for (int i = 0; i < N; ++i) {
        pq.push({ arr[i], i });
        int pos = pq.top().pos;
        while (pos < i - L + 1) {

            cout << "remove : " << pq.top().data << endl;
            pq.pop();
            pos = pq.top().pos;
        }
        cout << pq.top().data << ' ';
    }
    return 0;
}