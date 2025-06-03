#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long arr[100001];
long long ans = 0;

long long max_val = 0;

void binary_search(){

    long long left = 1, right = max_val;
    
    
    while( left <= right ){

        long long mid = (left + right) /2 ;
        long long cur_k = 0;    
        for (int i = 0; i < n; i++) {
            cur_k += arr[i] / mid;
        }

        if (cur_k >= k) {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else {
            right = mid -1;
        }
    }


}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_val = max(max_val, arr[i]);
    }


    binary_search();
    cout << ans << endl;
    
    
    return 0;
}