#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

//출처 : https: //jaimemin.tistory.com/1476 [꾸준함]
const int MAX = 5 * 1e5 + 1;
typedef struct {
    int ability, idx;
} State;
vector<int> segmentTree;
bool abilityCmp(State a, State b) { return a.ability < b.ability; }
bool idxCmp(State a, State b) { return a.idx < b.idx; }
int query(int start, int end, int node, int left, int right)
{
    cout << "s: " << start << " e: " << end << " node : " << node << " l: " << left << " r: " << right << endl;
    // right는 index값이어야하는데 ablity 값을 왜 넣지??
    // tree에서의 node 범위를 설정하기 위한 left right여야 하는데...
    if (start > right || end < left) {
        cout << " out range " << endl;
        return 0;
    }
    if (start >= left && end <= right) {

        cout << " in range " << endl;
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int idx)
{
    if (start > idx || end < idx) {
        return;
    }
    segmentTree[node]++;
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, idx);
    update(mid + 1, end, node * 2 + 1, idx);
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int height = (int)ceil(log2(MAX));
    int segmentTreeSize = 1 << (height + 1);
    segmentTree.resize(segmentTreeSize);
    vector<State> v(N);

    //v[i] 에 idx 부여 및 abil input 저장
    for (int i = 0; i < N; i++) {
        cin >> v[i].ability;
        v[i].idx = i;
    }

    // abil에 따라서 sorting
    // 구지 해줘야하나??
    sort(v.begin(), v.end(), abilityCmp);
    for (int i = 0; i < N; i++) {

        // sorting 후 abil에 따른 크기 순대로 i 로 저장
        v[i].ability = i;
        }

    //idx 별로 다시 sorting
    // 구지 다시 돌려줘야하나? 위에 것 안하면 되지 않을까?

    sort(v.begin(), v.end(), idxCmp);

    //segment tree 접근
    for (int i = 0; i < N; i++) {
        cout << " ----------quary -------" << endl;
        int frontRunners = query(0, MAX, 1, 0, v[i].ability);
        cout << i - frontRunners + 1 << "\n";
        update(0, MAX, 1, v[i].ability);
    }
    return 0;
}
