#include <algorithm>
#include <iostream>
using namespace std;

int tteok[500000];

//규칙성만보면 동일숫자가 가장 많은 개수에 의해 max값이 결정된다.
int main()
{
    ios::sync_with_stdio(false);

    int N, i, cnt = 1, max = 1;
    cin >> N;

    for (i = 0; i < N; i++)
        cin >> tteok[i];

    sort(tteok, tteok + N);

    for (i = 1; i < N; i++) {
        if (tteok[i] == tteok[i - 1]) {
            cnt++;
            if (cnt > max)
                max = cnt;
            //max update

        } else
            cnt = 1;
        //cnt를 1로 reset시켜버린다.
    }

    cout << max;

    return 0;
}