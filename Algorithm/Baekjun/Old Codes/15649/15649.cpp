#include <iostream>
#include <vector>
using namespace std;

const int MAX = 8 + 1;

int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;

                        cout << "i : " << i << endl;
                        cout << "func " << cnt + 1 << " in " << endl;
			dfs(cnt + 1);
                        cout << "func " << cnt + 1 << " out " << endl;

                        visited[i] = false;
		}
}

int main(void)
{
	cin >> N >> M;

	dfs(0);
	return 0;
}