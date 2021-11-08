#include <math.h>
#include <iostream>

using namespace std;


int main(int argc, char** argv)
{

    long long n;
    cin >> n;

    long long res = sqrt(n);

    if (res * res < n)
        res += 1;

    cout << res;

    return 0;
}

