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
    if (start > right || end < left) {
        return 0;
    }
    if (start >= left && end <= right) {
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
    for (int i = 0; i < N; i++) {
        cin >> v[i].ability;
        v[i].idx = i;
    }
    sort(v.begin(), v.end(), abilityCmp);
    for (int i = 0; i < N; i++) {
        v[i].ability = i;
    }
    sort(v.begin(), v.end(), idxCmp);
    for (int i = 0; i < N; i++) {
        int frontRunners = query(0, MAX, 1, 0, v[i].ability);
        cout << i - frontRunners + 1 << "\n";
        update(0, MAX, 1, v[i].ability);
    }
    return 0;
}
