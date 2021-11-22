#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s;

void solve() {
	string input = "start";

	while (input != ".")
	{
		bool suc_flag = true;
		input.clear();
		char input_c[101];
		cin.getline(input_c, 101);
		input = input_c;

		if (input == ".")
			break;

		for (auto it = input.begin(); it != input.end(); it++)
		{
			if (*it == '(' || *it == '[')
			{
				s.push(*it);
			}
			else if (*it == ')')
			{
				if (s.empty())
				{
					suc_flag = false;
					break;

				}

				char buf = s.top();
				if (buf == '(')
				{
					s.pop();
				}
				else {
					suc_flag = false;
					break;

				}
			}
			else if (*it == ']')
			{

				if (s.empty())
				{
					suc_flag = false;
					break;

				}
				char buf = s.top();
				if (buf == '[')
				{
					s.pop();
				}
				else {
					suc_flag = false;

					break;
				}

			}

		}
		if (!s.empty())
		{
			suc_flag = false;
			while (!s.empty())
			{
				s.pop();
			}
		}


		if (suc_flag == false)
		{
			suc_flag = true;
			cout << "no" << endl;

		}
		else
		{
			cout << "yes" << endl;
		}

	
		//while (!s.empty())
		//{

		//	char data = s.top();

		//	cout << data << endl;
		//	s.pop();


		//}

	}

}


int main()
{

	solve();



}