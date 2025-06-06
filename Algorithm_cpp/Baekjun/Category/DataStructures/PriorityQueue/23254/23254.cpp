#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;

struct test
{
    int score;
    int increase;
};

auto cmp = [](const test &a, const test &b) {
    
    return a.increase < b.increase || (a.increase == b.increase && a.score > b.score);
};

vector<int> a;
vector<int> b;

priority_queue<test, vector<test>, decltype(cmp)> pq(cmp);

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    a.resize(m);
    b.resize(m);

    int time = n * 24;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        struct test tmp;
        tmp.score = a[i];
        tmp.increase = b[i];
        pq.push(tmp);
    }

    while(time > 0) {
        
        int cur_score = pq.top().score;
        int cur_increase = pq.top().increase;
        pq.pop();

        if(100 - cur_score < cur_increase){
            pq.push({cur_score, 100 - cur_score});
            continue;
        }
        else{
            

            pq.push({cur_score + cur_increase, cur_increase});
        }
        time--;
    }

    int ans = 0;

    while(!pq.empty()){

        ans += pq.top().score;
        pq.pop();
    }
    cout << ans << "\n";

    return 0;
}