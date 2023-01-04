#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> tmp;
	for (int i = 0; i < numbers.size(); i++)
	{
		tmp.push_back(to_string(numbers[i]));
	}

	sort(tmp.begin(), tmp.end(), cmp);

	for (auto s : tmp)
	{
		cout << " s : " << s << endl;

		answer += s;
	}



	return answer;
}