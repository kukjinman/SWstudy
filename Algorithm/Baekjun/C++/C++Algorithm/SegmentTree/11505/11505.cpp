#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

//INT_MAX
#include <climits>

using namespace std;

int n = 0, m = 0, k = 0;

vector<long long> Arr;
vector<long long> Segment_Tree;

void input()
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        Arr.push_back(a);
    }
}

long long Make_SegmentTree(int node, int start, int end)
{
    // This needed to be fixed
    if (start == end) {
        Segment_Tree[node] = Arr[start];
        return Segment_Tree[node];
    }

    long long mid = (start + end) / 2;

    long long left_val = Make_SegmentTree(node * 2, start, mid);
    long long right_val = Make_SegmentTree(node * 2 + 1, mid + 1, end);
    Segment_Tree[node] = (left_val * right_val) % 1000000007;

    return Segment_Tree[node];
}

long long Query(int Node, int Start, int End, int Left, int Right)
{

    // This needed to be fixed

    // This is out of the Left and Right Range
    if (Right < Start || Left > End)
        return 1;

    // node별로 확인을 해보면, 아래의 Range는 Left보다 크고 Right보다 작은 query의 범위이다.
    if (Left <= Start && End <= Right)
        return Segment_Tree[Node];

    long long Mid = (Start + End) / 2;
    long long Left_Result = Query(Node * 2, Start, Mid, Left, Right);
    long long Right_Result = Query(Node * 2 + 1, Mid + 1, End, Left, Right);
    return (Left_Result * Right_Result) % 1000000007;
}

long long update(int node, int start, int end, int idx, int num)
{
    if (idx > end || idx < start) {
        return Segment_Tree[node];
    }
    if (start == end) {
        return Segment_Tree[node] = num;
    }

    long long Mid = (start + end) / 2;
    long long Left_Result = update(node * 2, start, Mid, idx, num);
    long long Right_Result = update(node * 2 + 1, Mid + 1, end, idx, num);

    return Segment_Tree[node] = (Left_Result * Right_Result) % 1000000007;
}

void node_printer()
{

    for (int i = 1; i < Segment_Tree.size(); i++) {

        cout << " node : " << i << " val : " << Segment_Tree[i] << endl;
    }
}

void solve()
{

    int Tree_Height = ceil(log2(n));
    // cout << "Tree_Height : " << Tree_Height << endl;

    int Tree_Size = (1 << (Tree_Height + 1));

    // cout << "Tree_Size : " << Tree_Size << endl;

    //vector resize 시 값이 없이 해당 크기 생성
    Segment_Tree.resize(Tree_Size);

    Make_SegmentTree(1, 0, n - 1);

    // node_printer();

    for (int i = 0; i < m + k; i++) {

        int cmd = 0;
        int a = 0;
        int b = 0;
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            //Update number
            // a-1이 들어가야하는 이유는 start의 시작이 0부터 시작하므로.
            update(1, 0, n - 1, a - 1, b);
            // node_printer();

        } else if (cmd == 2) {
            //print the multiplier
            long long ans = Query(1, 0, n - 1, a - 1, b - 1);
            cout << ans << endl;

        } else {
            cout << " this command is not defined " << endl;
        }
    }
}

int main(int argc, char* argv[])
{
    input();
    solve();

    return 0;
}