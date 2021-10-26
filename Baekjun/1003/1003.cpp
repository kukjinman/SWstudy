#include <iostream>

using namespace std;

int zeroCounter = 0;
int OneCounter = 0;

int T = 0;

int fibonacci(int n) {
    if (n == 0) {
        zeroCounter++;
        return 0;
    } else if (n == 1) {
        OneCounter++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N = 0;
        cin >> N;
        fibonacci(N);
        cout << zeroCounter << " " << OneCounter << endl;
    }

        return 0;
}
