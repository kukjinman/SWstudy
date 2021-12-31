#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n = 0;
#define max 1000001
int arr[max];

int main(int argc, char* argv[])
{
    int cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> arr[i];
    }

    int x = 0;
    cin >> x;

    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    while (left < right) {

        if (arr[left] + arr[right] == x) {
            right--;
            cnt++;
        } else if (arr[left] + arr[right] > x) {

            right--;
        } else {
            left++;
        }
    }

    cout << cnt;
    return 0;
}