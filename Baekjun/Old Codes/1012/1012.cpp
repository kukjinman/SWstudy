#include <iostream>
#include <queue>
#include <cstring>
#define Max 50

int map[Max][Max];
int visited[Max][Max];

int T, M, N, K;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bugCounter = 0;

using namespace std;

queue<pair<int, int>> q;

void printing()
{
        cout << endl;
    
    for (int i = 0; i < N; i++)
    {

        for (int j = 0;  j < M; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(int col, int row)
{
    q.push(make_pair(col, row));
    visited[col][row] = 1;

    while(!q.empty())
    {
    

        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
                    // cout << "[1] ny : " << ny << " nx : " << nx << endl;


            if( nx <0 || nx >=M || ny < 0 || ny >= N)
            {

                continue;
            }
            else{

                if(map[ny][nx] == 1 && visited[ny][nx] == 0)
                {
                    q.push(make_pair(ny, nx));
                    visited[ny][nx] = 1;
                    // cout << " ny : " << ny << " nx : " << nx << endl;

                }

            }


        }
    }

    bugCounter++;
}


void solve()
{

    for (int i = 0; i < N; i++)
    {

        for (int j = 0;  j < M; j++)
        {

            if(map[i][j] == 1 && visited[i][j] == 0)
            {
                // cout << " i : " << i << " j : " << j << endl;
                // cout << " map : " << map[i][j] << " visited : " << visited[i][j] << endl;
                bfs(i, j);

            }

        }
    }

    cout << bugCounter << endl;
}



void input()
{
    cin >> T;

    for (int i = 0; i < T; i ++)
    {

        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        bugCounter = 0;

        cin >> M >> N >> K;

        for (int j = 0; j < K; j++)
        {
            int tempX, tempY;
            cin >> tempX >> tempY;

            map[tempY][tempX] = 1;

        }

        solve();

        // printing();
        
    }

}





int main()
{

    input();




    return 0;
}


