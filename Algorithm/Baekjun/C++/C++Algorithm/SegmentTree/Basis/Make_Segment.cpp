#include <algorithm>
#include <iostream>
#include <vector>


void solve()
{

    // ex) n = 5 -> height = ceil(2.xxx)
    // ex) n = 10 -> height = ceil(3.xxx)
    int t_height = ceil(log2(n));
    cout << "t_height : " << t_height << endl;

    //2�� height���� 1�´� ū ������ size����
    int t_size = (1 << (t_height + 1));
    cout << "t_size : " << t_size << endl;

    seg_tree.resize(t_size);

    Make_SegmentTree(1, 0, n - 1);
}


int Make_SegmentTree(int node, int start, int end)
{

    if (start == end)
    {
        seg_tree[node] = arr[start];
        return seg_tree[node];
    }

    int mid = (start + end) / 2;

    int mid_left = Make_SegmentTree(node * 2, start, mid);
    int mid_right = Make_SegmentTree(node * 2 + 1, mid + 1, end);
    seg_tree[node] = mid_left + mid_right;

    return seg_tree[node];

}