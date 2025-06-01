#include <iostream>
#include <algorithm>
using namespace std;

void binary_search(int arr[], int n, int target)
{
    bool res = false;
    int left = 0;
    int right = n - 1;

    while( left <= right){
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            res = true;
        }
        else if (arr[mid] < target){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }

    if (res) {
        cout << "1\n";
    } else {
        cout << "0\n";

}


void main(int argc, char* argv[])
{
    int n = 0;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int m = 0;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int target = 0;
        cin >> target;

        // Binary search
        if (binary_search(arr, arr + n, target)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}