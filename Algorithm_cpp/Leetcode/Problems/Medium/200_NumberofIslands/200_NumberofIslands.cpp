class Solution {
public:

    int dy[4] = { -1,1,0,0 };
    int dx[4] = { 0,0,-1,1 };

    int ans = 0;



    void bfs(int y_, int x_, int m_, int n_, vector<vector<char>> map_, vector<vector<int>>& visited)
    {
        queue<pair<int, int>> q;
        q.push(make_pair(y_, x_));
        visited[y_][x_] = true;

        while (!q.empty())
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();


            for (int i = 0; i < 4; i++)
            {
                int ny = dy[i] + y;
                int nx = dx[i] + x;

                if (ny >= m_ || ny < 0 || nx >= n_ || nx < 0)
                {
                    continue;
                }

                if (map_[ny][nx] == '0') continue;

                if (visited[ny][nx]) continue;

                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;

            }







        }



    }

    void solve(vector<vector<char>> map)
    {
        int m = map.size();
        int n = map[0].size();
        vector<vector<int>> visited;
        visited.resize(m, vector<int>(n, 0));
        cout << " m : " << m << " n : " << n << endl;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == '1')
                {
                    if (!visited[i][j]) {
                        bfs(i, j, m, n, map, visited);
                        ans++;

                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        solve(grid);
        return ans;
    }
};