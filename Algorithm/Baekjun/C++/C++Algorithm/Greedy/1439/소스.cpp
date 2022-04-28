#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
	cin >> s;

	char first = s.at(0);
	char buf = 0;

	int count = 0;
	
	
	for (int i = 1; i < s.length(); i++)
	{
		if (s.at(i) != first  && s.at(i) != buf)
		{
			count++;
		}

		buf = s.at(i);

	}

	cout << count << endl;
	return 0;
}