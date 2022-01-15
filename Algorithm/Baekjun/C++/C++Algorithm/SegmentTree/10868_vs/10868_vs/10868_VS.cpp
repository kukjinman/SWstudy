#include <algorithm>
#include <iostream>
#include <vector>

//INT_MAX
#include <climits>

//log2 and ceil
#include <cmath>

//stl의 endl를 사용시 timeout남....
#define endl "\n"

using namespace std;

int n = 0, m = 0;

vector<int> Arr;
vector<int> Segment_Tree;
vector<pair<int, int>> Cmd;


void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        Arr.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Cmd.push_back(make_pair(a, b));
    }
}

int Make_SegmentTree(int node, int start, int end)
{

    if (start == end) {
        Segment_Tree[node] = Arr[start];
        return Segment_Tree[node];
    }

    int mid = (start + end) / 2;

    int min_left = Make_SegmentTree(node * 2, start, mid);
    int min_right = Make_SegmentTree(node * 2 + 1 , mid + 1, end);
    Segment_Tree[node] = min(min_left, min_right);

    return Segment_Tree[node];
}

int Query(int Node, int Start, int End, int Left, int Right)
{
    if (Right < Start || Left > End)
        return 2e9;
    if (Left <= Start && End <= Right)
        return Segment_Tree[Node];

    int Mid = (Start + End) / 2;
    int Left_Result = Query(Node * 2, Start, Mid, Left, Right);
    int Right_Result = Query(Node * 2 + 1, Mid + 1, End, Left, Right);
    return min(Left_Result, Right_Result);
}

void solve()
{

    int Tree_Height = ceil(log2(n));
    //cout << "Tree_Height : " << Tree_Height << endl;

    int Tree_Size = (1 << (Tree_Height + 1));

    //cout << "Tree_Size : " << Tree_Size << endl;

    //vector resize 시 값이 없이 해당 크기 생성
    Segment_Tree.resize(Tree_Size);

    Make_SegmentTree(1, 0, n - 1);

    for (int i = 0; i < Cmd.size(); i++) {

        //cout << " cmd 1 : " << Cmd[i].first - 1 << " cmd 2 : " << Cmd[i].second - 1 << endl;
        
        int Index = Cmd[i].first - 1;
        int Index2 = Cmd[i].second - 1;
        
        
        cout << Query(1, 0, n - 1, Index, Index2) << endl;
    }
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    input();
    solve();

    return 0;
}