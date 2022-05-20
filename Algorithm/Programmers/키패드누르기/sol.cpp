#include <cstring>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    int r_pos = -1;
    int l_pos = -1;

    for (int i = 0; i < numbers.size(); i++) {

        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            l_pos = numbers[i];
            answer += "L";
        } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            r_pos = numbers[i];
            answer += "R";
        } else {
            int l_dist = 0;
            int r_dist = 0;
        }
    }

    return answer;
}