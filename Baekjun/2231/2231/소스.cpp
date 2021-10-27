#include <iostream>
#include <queue>
using namespace std;


int N, M, V;

#define MAX 1001

int adj[MAX][MAX];
int visited[MAX];

queue<int> q;

void input()
{
	cin >> N >> M >> V;

	for (int i = 1; i < N + 1; i++)
	{
		adj[N][M] = 1;
		adj[M][N] = 1;

	}


}

void dfs()
{



}



void bfs()
{



}


int main()
{

	input();






	return 0;
}
