#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    priority_queue<int> pq;
    int my_vote = 0;
    for (int i = 0; i < n; i++) {
        int x;
        if (i == 0) {
            cin >> my_vote;
            continue; // Skip the first input as it is already pushed
        }
        cin >> x;
        pq.push(x);
    }

    int ans = 0;

    if(pq.empty()) {
        cout << 0 << endl; // If there are no other votes, no operations needed
        return 0;
    }
    
    while(pq.top() >= my_vote) {
        int top_vote = pq.top();
        pq.pop();
        top_vote--; // Decrease the top vote by 1
        my_vote++; // Increase my vote by 1
        pq.push(top_vote); // Push the modified vote back into the priority queue
        ans++; // Increment the answer (number of operations)
    }

    if (ans < 0) {
        ans = 0; // Ensure the answer is not negative
    }

    cout << ans << endl;


    return 0;
}