#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<pair<int, int>> v_road[51];
int res[51];


struct cmp {
    bool operator()(pair<int, int>a, pair<int, int>b) {
        return a.second > b.second;
    }
};

void search(int k_)
{
    res[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
    pq.push(make_pair(1, 0));

    while (!pq.empty())
    {
        int cur = pq.top().first;
        int dist = pq.top().second;
        pq.pop();   

        cout << "cur : " << cur << " dist : " << dist << endl;

        for (int i = 0; i < v_road[cur].size(); i++)
        {
            int next = v_road[cur][i].first;
            int n_dist = dist +v_road[cur][i].second;
            //cout << "next : " << next << " n_dist : " << n_dist << endl;

            if (n_dist < res[next])
            {
                res[next] = n_dist;
                pq.push(make_pair(next, n_dist));
            }

        }
            

    }

}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i < 51; i++)
    {
        res[i] = 1000000;
    }

    for (auto v : road)
    {
        
        int start = v[0];
        int des = v[1];
        int dist = v[2];

        v_road[start].push_back(make_pair(des, dist));
        v_road[des].push_back(make_pair(start, dist));


    }

    search(K);

    return answer;
}