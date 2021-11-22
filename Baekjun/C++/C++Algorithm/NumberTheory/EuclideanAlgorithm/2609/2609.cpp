
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b, int greatCommonDivisor)
{
    return (a * b) / greatCommonDivisor;
}

int main(int argc, char* argv[])
{
    int a, b;

    cin >> a >> b;

    int greatest_common_factor = gcd(a, b);
    int least_common_multiple = lcm(a, b, greatest_common_factor);

    cout << greatest_common_factor << '\n'
         << least_common_multiple;

    return 0;
}