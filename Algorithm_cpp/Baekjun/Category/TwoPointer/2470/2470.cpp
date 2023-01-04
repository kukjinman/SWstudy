#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n = 0;
#define max 1000001
long long arr[max];

int main(int argc, char* argv[])
{
    long long x, y = 0;

    long long min = LLONG_MAX;

    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> arr[i];
    }

    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    while (left < right) {

        int sum = arr[left] + arr[right];

        if (abs(sum) < min) {

            min = abs(sum);
            x = arr[left];
            y = arr[right];

            if (sum == 0)
                break;
        }

        if (sum < 0)
            left++;
        else {
            right--;
        }
    }

    cout << x << " " << y << endl;
    return 0;
}