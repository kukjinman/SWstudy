#include <deque>
#include <iostream>
#include <string>

using namespace std;

#define MAX 1000000

int arr[MAX];

deque<int> q;

int main()
{
    int n = 0;
    cin >> n;
    int ans = n;

    for (int i = 0; i < n; i++) {

        int first = 0;

        cin >> first;
        arr[first]++;
    }
    for (int i = 0; i < n; i++) {

        int second = 0;

        cin >> second;
        q.push_back(second);
    }

    while (!q.empty()) {
        int val = q.front();
        q.pop_front();
        // cout << " val : " << val << endl;
        if (arr[val] > 0) {

            // cout << "  arr : " << arr[val] << endl;

            arr[val]--;
            ans--;

        } else {
        }
    }

    cout << ans << endl;

    return 0;
}
