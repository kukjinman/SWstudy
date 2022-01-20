
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

//범위의 최소값
//10868 예시 문제

int Update(int node, int start, int end)
{

    if (start == end) {
        Segment_Tree[node] = Arr[start];
        return Segment_Tree[node];
    }

    int mid = (start + end) / 2;

    int min_left = Make_SegmentTree(node * 2, start, mid);
    int min_right = Make_SegmentTree(node * 2, mid + 1, end);
    Segment_Tree[node] = min(min_left, min_right);

    return Segment_Tree[node];
}
