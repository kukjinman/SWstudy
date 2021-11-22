// 2667_exe.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;


int N, M, V;

#define MAX 25

string map[MAX];
int visited[MAX][MAX];


int dx[4] = { -1 , 1 , 0, 0 };
int dy[4] = { 0,0,-1,1 };

list<int> danjiCounter;

queue<pair<int, int>> q;

void input()
{
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> map[i];

	}


}


void bfs(int x, int y)
{
	q.push(pair<int,int>(x,y));

	visited[x][y] = 1;

	int tempCounter = 0;

	while (!q.empty())
	{
		int NextX = q.front().first;
		int NextY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			NextX = NextX + dx[i];
			NextY = NextY + dy[i];

			if (NextX < 0 || NextX >= N || NextY < 0 || NextY >= N)
			{
				continue;
			}
			else {
				// Inside the boundary

				if (map[NextX][NextY] == '1' && visited[NextX][NextY] != 1)
				{

					q.push(pair<int, int>(NextX, NextY));
					visited[NextX][NextY] = 1;

					cout << "X : " << NextX << "Y : " << NextY << endl;
					tempCounter++;
				}





			}

		}




	}

	danjiCounter.push_back(tempCounter);


}
bool myfunction(int i, int j) { return (i < j); }


void solve()
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{


			if (map[i][j] == '1' && visited[i][j] != 1)
			{

				bfs(i, j);

			}

		}
	}
	danjiCounter.sort();

	//sort(danjiCounter.begin(), danjiCounter.end(), myfunction);

	for (auto item : danjiCounter)
		cout << danjiCounter.front();
}


int main()
{

	input();

	solve();




	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
