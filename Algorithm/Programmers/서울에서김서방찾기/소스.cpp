#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    answer += "김서방은 ";

    auto it = find(seoul.begin(), seoul.end(), "Kim");
    int index = it - seoul.begin();
    answer += to_string(index);

    answer += "에 있다";

    return answer;
}