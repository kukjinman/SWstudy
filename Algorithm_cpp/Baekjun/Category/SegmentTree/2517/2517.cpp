
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = INT_MAX;
vector<int> segmentTree;

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
