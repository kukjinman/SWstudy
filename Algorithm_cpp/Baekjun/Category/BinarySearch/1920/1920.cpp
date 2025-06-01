#include <iostream>
#include <algorithm>
using namespace std;

bool binary_search(int arr[], int n, int target)
{

    bool res = false;
    int left = 0;
    int right = n - 1;

    while( left <= right){
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            res = true;
            return res; // Found the target, return true
        }
        else if (arr[mid] < target){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }


    return res;
}


int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);cin.tie(0);
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
        if (binary_search(arr, n, target)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}