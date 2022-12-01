#include <iostream>
#include <vector>
#include <algorithm>

int ans = 10000000;
int n;
int m;
using namespace std;

vector<vector<char>> board;


void solve()
{



    for (int i = 0; i < n - 7; i++)
    {
        for (int j = 0; j < m - 7; j++)
        {
            int w_first_cnt = 0;
            int b_first_cnt = 0;


            // w first counting
            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    if ((i + y + j + x) % 2 == 0 && board[i + y][j + x] != 'W')
                    {
                        w_first_cnt++;
                    }
                    else if ((i + y + j + x) % 2 == 1 && board[i + y][j + x] != 'B')
                    {
                        w_first_cnt++;

                    }


                }
            }

            // w first counting
            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    if ((i + y + j + x) % 2 == 0 && board[i + y][j + x] != 'B')
                    {
                        b_first_cnt++;

                    }
                    else if ((i + y + j + x) % 2 == 1 && board[i + y][j + x] != 'W')
                    {
                        b_first_cnt++;

                    }
                }
            }

            //cout << " w : " << w_first_cnt << endl;
            //cout << " b : " << b_first_cnt << endl;
            ans = min(ans, w_first_cnt);
            ans = min(ans, b_first_cnt);
        }
    }




}


int main()
{
    cin >> n >> m;
    board.resize(n, vector<char>(m, 0));


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];


        }
    }


    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < m; j++)
    //    {
    //        cout << board[i][j] << " ";


    //    }
    //    cout << endl;
    //}

    solve();


    cout << ans << endl;
}
