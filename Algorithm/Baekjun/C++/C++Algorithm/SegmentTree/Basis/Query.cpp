

//구간 합 쿼리

int Query(int Node, int Start, int End, int Left, int Right)
{

    //범위에서 벗어남으로 합에 영향을 미치지 않는 0 return
    if (Right < Start || Left > End) // 2
        return 0;

    if (Left <= Start && End <= Right) // 1
        return Segment_Tree[Node];

    int Mid = (Start + End) / 2;
    return Query(Left, Right, 2 * Node, Start, Mid) + Query(Left, Right, 2 * Node + 1, Mid + 1, End); // 3
}

// 구간 최소값 쿼리
int Query(int Node, int Start, int End, int Left, int Right)
{
    if (Right < Start || Left > End)
        return INT_MAX;
    if (Left <= Start && End <= Right)
        return Segment_Tree[Node];

    int Mid = (Start + End) / 2;
    int Left_Result = Query(Node * 2, Start, Mid, Left, Right);
    int Right_Result = Query(Node * 2 + 1, Mid + 1, End, Left, Right);
    return min(Left_Result, Right_Result);
}
