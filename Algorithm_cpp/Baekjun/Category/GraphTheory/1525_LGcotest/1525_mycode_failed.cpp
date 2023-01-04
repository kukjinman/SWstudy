#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

set<vector<vector<int>>> visited;

vector<vector<int>> puz, ans;

void printer(vector<vector<int>> map_)
{
    cout << "-----------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << map_[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------  - end " << endl;
}

void input()
{
    puz.resize(3, vector<int>(3, 0));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int tmp = 0;
            cin >> tmp;

            puz[i][j] = tmp;

        }
    }
    // printer(puz);

    //answer puz
    ans.resize(3, vector<int>(3, 0));

    int cnt = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = cnt++;
        }
    }
    ans[2][2] = 0;
    // printer(ans);
}

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void zero_finder(int& y, int& x, vector<vector<int>> v)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (v[i][j] == 0)
            {
                y = i;
                x = j;
                return;
            }

        }


    }

    return;
}

int solve()
{
    queue<pair<vector<vector<int>>, int>> q;
    q.push(make_pair(puz, 0));

    while (!q.empty())
    {
        vector<vector<int>> cur_puz = q.front().first;
        int cnt = q.front().second;
        visited.insert(cur_puz);
        q.pop();

        if (cur_puz == ans)
        {
            return cnt;
        }

        //find 0
        int y = 0;
        int x = 0;
        zero_finder(y, x, cur_puz);


        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= 3 || nx >= 3)
                continue;

            vector<vector<int>> cur = cur_puz;
            // printer(cur);
            swap(cur[y][x], cur[ny][nx]);
            // printer(cur);

            if (visited.find(cur) == visited.end())
            {
                // cout << " Not Exixt" << endl;
                visited.insert(cur);
                q.push(make_pair(cur, cnt + 1));
            }
            else
            {
                // cout << " Exist " << endl;
            }

            cur = cur_puz;

        }

    }

    return -1;
}



int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // vector<vector<int>> tmp_v;
    // set<vector<vector<int>>> v;
    // tmp_v.resize(3,vector<int>(3,0));
    // v.insert(tmp_v);
    // cout << " size vector<vector<int>> : " << sizeof(tmp_v) << " v : " << sizeof(v) <<  endl;

    // string tmp;
    // tmp = "0123456789";
    // set<string> s;
    // s.insert(tmp);
    // cout <<  " s : " << sizeof(s) <<  endl;


    input();
    int res = solve();

    cout << res << endl;
    return 0;
}