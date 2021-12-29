#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 502

int n;
int link_num[MAX];
int build_time[MAX];

vector<int> v[MAX];

//가장 필수 건물부터 계속 link된 건물들까지
//하나하나 순서대로 보기위해 queue를 사용하여 다음 action을 줌
queue<int> q;
int res[MAX];

void input()
{
    cin >> n;

    for (int i = 1; i < n + 1; i++) {
        int t = 0;
        cin >> t;
        build_time[i] = t;

        while (1) {
            int a = 0;
            cin >> a;
            if (a == -1)
                break;
            else {
                //v[a]는 a를 바라보고 있는 i들에 대해서 vector에 추가해줌
                v[a].push_back(i);
                //link_num은 i가 link하여 바라보고 있는 갯수
                link_num[i]++;
            }
        }
    }

    // for (int i = 1; i < n + 1; i++) {

    //     for (int j = 0; j < v[i].size(); j++) {
    //         cout << " v [" << i << "] : " << v[i].at(j);
    //     }
    //     cout << endl;
    // }
}

void solve()
{

    //다른 빌딩의 link를 하지 않는 필수 건물들을 q에 우선적으로 넣어줌
    for (int i = 1; i < n + 1; i++) {
        if (link_num[i] == 0) {
            q.push(i);

            // 현재 if의 res[i]를 지금 입력해주는 이유는
            // 이후 q에 다시 들어갈 일이 없기 때문
            res[i] = build_time[i];
        }
    }
    //우선적으로 넣어준 필수 건물들에 대해서
    //해당 건물을 link하고 있는 건물들을 차례대로 q에 추가하여
    //res값을 update함.
    while (!q.empty()) {

        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {

            // v[cur]의 현재 q에서 받아온 cur을 바라보고 있는 다음 node들에 대하여
            //결과값 계산
            int next = v[cur].at(i);

            res[next] = max(res[next], res[cur] + build_time[next]);
            link_num[next]--;

            //next가 link하여 바라보고 있는 필수 건물이 더이상 없으면
            // q에 넣어서 next node를 바라보는 그 다음 next 건물들을 계산해야 함.
            // 0이 아닐시 추가를 하면 q에 중복되어 여러번 추가되어 한번만 하기 위해
            //해당 if문을 사용 함.
            if (link_num[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i < n + 1; i++) {

        cout << res[i] << endl;
    }
}

int main(int argc, char* argv[])
{
    input();
    solve();

    return 0;
}