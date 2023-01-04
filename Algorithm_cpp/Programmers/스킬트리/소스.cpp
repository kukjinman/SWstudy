#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	map<char, int> mp;
	for (int i = 0; i < skill.size(); i++)
	{
		mp[skill[i]] = i + 1;

	}

	int level = 1;
	bool possible_flag = true;
	for (string s : skill_trees)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (mp[s[i]] > level)
			{
				// cout <<"impossible case " <<endl;
				possible_flag = false;
				break;
			}
			else if (mp[s[i]] == level)
			{
				level++;

			}
			else
			{
				// cout << "not defined " << endl;
			}

		}

		if (possible_flag == true)
		{
			cout << " ans : " << s << endl;
			answer++;
		}
		possible_flag = true;
		level = 1;

	}


	return answer;
}