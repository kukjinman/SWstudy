#include <algorithm>
#include <iostream>
using namespace std;

int A[51];
int B[51];
int n;

bool cmp(const int& a, const int& b)
{
    if (a > b)
        return true;
    else {
        return false;
    }
}

void printer()
{
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    for (int j = 0; j < n; j++) {
        cout << B[j] << " ";
    }
}

void input()
{

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> B[j];
    }

    // printer();
}

void solve()
{
    sort(A, A + n);

    sort(B, B + n, cmp);

    // printer();

    int res = 0;

    for (int i = 0; i < n; i++) {
        res += A[i] * B[i];
    }

    cout << res;
}

int main(int argc, char* argv[])
{

    input();
    solve();

    return 0;
}