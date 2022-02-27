#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

vector<int> arr;

vector<int> seg_tree;

void input()
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        arr.push_back(tmp);
    }




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

long long update(int node, int start, int end, int idx, int num)
{
    if (idx > end || idx < start) {
        return seg_tree[node];
    }
    if (start == end) {
        return seg_tree[node] = num;
    }

    long long Mid = (start + end) / 2;
    long long Left_Result = update(node * 2, start, Mid, idx, num);
    long long Right_Result = update(node * 2 + 1, Mid + 1, end, idx, num);

    return seg_tree[node] = (Left_Result * Right_Result) % 1000000007;
}

void node_printer()
{

    for (int i = 1; i < seg_tree.size(); i++) {

        cout << " node : " << i << " val : " << seg_tree[i] << endl;
    }
}


void solve()
{
    int t_height = ceil(log2(n));
    cout << "t_height : " << t_height << endl;

    int t_size = (1 << (t_height + 1));
    cout << "t_size : " << t_size << endl;

    seg_tree.resize(t_size);

    Make_SegmentTree(1, 0, n - 1);


    //command loop

    for (int i = 0; i < m + k; i++)
    {
        int a = 0;
        cin >> a;

        if (a == 1)
        {
            int b = 0;
            int c = 0;
            int d = 0;

            cin >> b >> c >> d;

            node_printer();




        }
        else if (a == 2)
        {



        }




    }

}


int main(int argc, char* argv[])
{
    input();
    solve();

    return 0;
}