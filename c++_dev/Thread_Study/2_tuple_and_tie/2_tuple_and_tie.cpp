#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    auto t = make_tuple(1, 2, 3);

    int x = get<0>(t);
    int y = get<1>(t);
    int z = get<2>(t);

    cout << x << ' ' << y << ' ' << z << '\n'; //1 2 3

    x = y = z = 0;
    cout << x << ' ' << y << ' ' << z << '\n'; //0 0 0

    // tuple의 변수를 각 인자 변수 type으로 반환하여 주는 tie 함수
    std::tie(x, y, z) = t;
    cout << x << ' ' << y << ' ' << z << '\n'; //1 2 3

    x = y = z = 0;
    std::tie(x, y, ignore) = t; //세번째 자리는 무시 키워드 : ignore
    cout << x << ' ' << y << ' ' << z << '\n'; //1 2 0

    return 0;
}
