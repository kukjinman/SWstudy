
//점갱신
//A[X] = V 로 갱신
#define SIZE (1 << 20)

int A[2 * SIZE];
int Update(int X, int V, int node, int start, int end)
{

    if (start == end) {
        A[node] = V;
        return Segment_Tree[node];
    }

    int mid = (start + end) / 2;

    if (X <= mid)
        Update(X, V, 2 * node, start, mid);
    else
        Update(X, V, 2 * node + 1, mid + 1, end);
}


// 11505 문제 idx값에 num값 update
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