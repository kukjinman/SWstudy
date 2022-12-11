#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<pair<long, long>> v;
priority_queue<long long> pq;


// 도수의 최소값을 찾는데, 도수는 누적되지 않고 매일 갱신된다.
// 그러므로 도수 값을 오름차순으로 정렬하여 제일 작은 수부터 올라가는 loop를 태운다
// loop안에서 선호도 값을 -로 넣어주어 제일 작은 절대값을 top으로 오게 해준다. (cmp를 사용해도 됨)
// pq를 사용하여 작은 선호도를 n값이 넘으면 빼준다. 다음 v[i]가 작은 선호도의 pq.top을 대신하여 들어가서 
// sum>=m 확인을 하게 됨.
// 만족하면 return으로 종료


int main(int argc, char** argv)
{

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        long long like = 0;
        long long alc = 0;
        cin >> like >> alc;

        v.push_back(make_pair(alc, like));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        //cout << " vi f: " << v[i].first << " s : " << v[i].second << endl;

    }
    //cout << " ---------------------------" << endl;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        //cout << " vi f: " << v[i].first << " s : " << v[i].second << endl;
        pq.push(-v[i].second);
        sum += v[i].second;

        if (pq.size() > n)
        {
            
            sum += pq.top();
            pq.pop();
        }

        if (pq.size() == n && sum >= m)
        {
            cout << v[i].first << endl;
            return 0;
        }

    }

    cout << "-1" << endl;

    return 0;
}
