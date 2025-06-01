#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int k, n;
int max_val = 0;

void binary_search(){

    long long ans = 0;
    long long left = 1;
    long long right = max_val;
    long long mid;

    while(left <= right) {
        mid = (left + right) /2;
        int cnt = 0;
        
        for (auto& i : arr) {
            cnt += i / mid;
        }

        if (cnt >= n){
            left = mid + 1; // We can make more cables, try longer length
            ans = max(ans, mid); // Update the answer
        } else {
            right = mid - 1; // We cannot make enough cables, try shorter length
        }
    }

    cout << ans << "\n"; // The maximum length of cable we can cut

}



int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> k >> n;
    arr.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        if (arr[i] > max_val)
            max_val = arr[i];
    
    }

    binary_search();
    return 0;
}

