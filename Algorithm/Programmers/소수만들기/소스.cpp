#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
	if (num < 2)
		return false;

	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

int result = 0;


void dfs(int cnt, int level, int sum, vector<int> v_) {


	int tmp = sum;
	if (level == 3) {
		// cout << " tmp : " << tmp << endl;

		if (isPrime(sum)) {
			// cout << "Prime" << endl;
			result++;
		}
		else {

		}

		return;
	}


	for (int i = cnt; i < v_.size(); i++) {

		// cout << " v[i] : " << v_[i] << endl; 
		tmp += v_[i];
		dfs(i + 1, level + 1, tmp, v_);
		tmp = sum;

	}


}


int solution(vector<int> nums) {
	int answer = -1;

	dfs(0, 0, 0, nums);
	answer = result;
	return answer;
}