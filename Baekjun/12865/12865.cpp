#include <stdio.h>
#include <iostream>


using namespace std;

int N;
int K;

int W[101];
int V[101];

bool visited[101];

int HIGH_W = 0;
int HIGH_V = 0;


void input()
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> W[i] >> V[i];
    }

}

void DFS( int idx, int cur_W, int cur_V)
{

    for (int i = 0; i < N; i ++)
    {
        if(!visited[i])
        {
            if(cur_W > K)
            {
                return ;
            }
            else
            {
                if(cur_V > HIGH_V)
                {
                    HIGH_V = cur_V;
                }

                DFS(i, cur_W + W[i], cur_V + V[i]);
            }
            
            
        }
        
    }

    return;
}



int main() {

    input();
    DFS(0, 0, 0);
    cout << HIGH_V << endl;

    return 0;
}
