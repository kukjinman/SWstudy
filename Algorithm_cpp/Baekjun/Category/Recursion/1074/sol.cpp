#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int N, C, i, j;
int position;

// x : 전체를 4 구역으로 나눴을 때, 섹션 크기를 구하기 위해 사용되는 변수
// 즉 4구역을 나눴을 때, 문제에서 각 구역의 시작 수를 말함.
// n : 한 변의 길이
void real(int x, int n)
{

    if (n == 1)
        return;

    int en = pow(4, x - 1);

    int A_START = 0;
    int B_START = en;
    int C_START = en * 2;
    int D_START = en * 3;

    if (i <= n / 2 - 1 && j <= n / 2 - 1) {
        // SECTION A
        position += A_START;
    } else if (i <= n / 2 - 1 && j <= n - 1) {
        // SECTION B
        position += B_START;
        j -= n / 2;
    } else if (i <= n - 1 && j <= n / 2 - 1) {
        // SECTION C
        position += C_START;
        i -= n / 2;
    } else if (i <= n - 1 && j <= n - 1) {
        // SECTION D
        position += D_START;
        i -= n / 2;
        j -= n / 2;
    }
    real(x - 1, n / 2);
}

int main()
{

    scanf("%d", &N);
    scanf("%d %d", &i, &j);

    C = N;
    N = pow(2, N); // 한 변의 크기

    real(C, N);

    printf("%d", position);
}