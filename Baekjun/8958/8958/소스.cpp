#include <iostream>
#include <string>
using namespace std;

#define MAX 81



void solve()
{
	int T;
	
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string input_s;
		int score = 0;
		int c_score = 0;


		cin >> input_s;

		int index = 0;
		while (input_s[index] != NULL)
		{

			//cout << input_s[index];
			if (input_s[index] == 'O')
			{
				c_score++;

			}
			else {

				c_score = 0;


			}

			score += c_score;
			index++;

		}

		cout << score << endl;






	}




}


int main()
{
	solve();


	return 0;
}










