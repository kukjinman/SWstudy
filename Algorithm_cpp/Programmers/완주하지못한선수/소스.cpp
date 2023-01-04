#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	map<string, int> mp;

	for (int i = 0; i < completion.size(); i++)
	{
		mp[completion[i]]++;

	}

	for (int i = 0; i < participant.size(); i++) {

		// cout << " com : " << participant[i] << endl;
		if (mp[participant[i]] >= 1)
		{
			// cout << " test 1 " << endl;
			mp[participant[i]]--;
			continue;
		}
		else
		{
			// cout << " test 2" << endl;

			answer = participant[i];
			break;
		}


	}



	return answer;
}