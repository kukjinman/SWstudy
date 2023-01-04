#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//계속 update를 해주면서 가장 low한 값이 loop를 돌며 앞에서 계산되어야 함
//priority queue말고는 답이 없음.

int solution(vector<int> scoville, int K) {
	int answer = 0;
	sort(scoville.begin(), scoville.end());

	int cur_sum = scoville.at(0);

	
	cout << "first  sum : " << cur_sum << endl;

	for (int i = 1; i < scoville.size(); i++)
	{

		if (cur_sum < K)
		{

			if (cur_sum < scoville.at(i)) {

				cur_sum += scoville.at(i) * 2;
				cout << " 1sum : " << cur_sum << endl;
				answer++;

			}
			else
			{
				int tmp = scoville.at(i) + cur_sum * 2;
				cur_sum = tmp;
				cout << " 2sum : " << cur_sum << endl;
				answer++;
			}
		}
		else if (scoville.at(i) < K)
		{
			int tmp = scoville.at(i) + cur_sum * 2;
			cur_sum = tmp;
			cout << " 3sum : " << cur_sum << endl;


			answer++;
		}
		else
		{
			cout << " cur_ sum : " << cur_sum << endl;
			break;
		}

	}
	return answer;
}