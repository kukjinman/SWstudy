#include <iostream>


int N, M;

int Num[100];


using namespace std;
void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> Num[i];

	}


}

void solve()
{
	int max = 0;

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i+1; j < N - 1; j++)
		{

			for (int k = j+1; k < N; k++)

			{
				int tempMax = 0;
				tempMax = Num[i] + Num[j] + Num[k];

				if (max < tempMax && tempMax <= M)
				{
					max = tempMax;

					//cout << i << " " << j << " " << k << " " << endl;
					//cout << "temp : " << tempMax << endl;

				}

			}


		}


	}

	cout << max;


}


int main()
{

	input();

	solve();






	return 0;
}


