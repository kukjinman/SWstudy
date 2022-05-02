
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v;

int main(int argc, char** argv)
{

    /* cin, cout 입출력 속도 향상 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int L = 0;
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int a = 0;
        cin >> a;
        v.push_back(a);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < N; i++) {

        pq.push(make_pair(v.at(i), i));
        //현재 pq top의 위치
        int pos = pq.top().second;

        //pos data를 저장해서 pq의 top에 있는 queue가 L인덱스를 넘어서 남아있지 않도록 함.
        // while을 사용하는 이유는 top의 queue가 pop될때까지 이전 queue들의 data의  pos는 다시 계산해서 pop해줘야함으로
        while (pos < i - L + 1) {
            pq.pop();
            pos = pq.top().second;
        }

        cout << pq.top().first << " ";
    }

    return 0;
}
