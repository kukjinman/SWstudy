#include <iostream>
#include <string>

using namespace std;

void solve()
{
	int T;
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		int dup_counter = 0;
		string s;

		cin >> dup_counter;

		cin >> s;

		for (int j = 0; j < dup_counter; j++)
		{
			cout << s[j];


		}




	}


}






int main()
{
	solve();



	return -1;
}