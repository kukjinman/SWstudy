#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    bool dot_flag = false;

    // cout << new_id << endl;

    for (int i = 0; i < new_id.size(); i++) {
        char c = new_id[i];
        // cout << " c : " << c << endl;

        if (int(c) >= 65 && int(c) <= 90) {
            //대문자
            int tmp = int(c);
            tmp += 32;
            new_id[i] = char(tmp);
        } else if ((int(c) >= 97 && int(c) <= 122) || (int(c) >= 48 && int(c) <= 57) || c == '-' || c == '_' || c == '.') {

        } else {
            // cout << " special : " << c << endl;
            new_id.erase(new_id.begin() + i);
            i--;
        }

        if (c == '.') {
            if (dot_flag == false) {
                dot_flag = true;

            } else {
                new_id.erase(new_id.begin() + i);
                i--;
            }

        } else {
            dot_flag = false;
        }
    }
    // cout << new_id << endl;

    dot_flag = false;
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.') {
            if (dot_flag == false) {
                dot_flag = true;

            } else {
                new_id.erase(new_id.begin() + i);
                i--;
            }

        } else {
            dot_flag = false;
        }
    }

    while (new_id[0] == '.') {
        // cout << " new_id : " << new_id[0] << endl;
        new_id.erase(new_id.begin());
    }
    while (new_id[new_id.size() - 1] == '.') {
        // cout << "[last] new_id : " << new_id[0] << endl;

        new_id.erase(new_id.end() - 1);
    }

    if (new_id.size() > 15) {
        new_id = new_id.substr(0, 15);
    }
    cout << new_id << endl;

    while (new_id[0] == '.') {
        new_id.erase(new_id.begin());
    }
    while (new_id[new_id.size() - 1] == '.') {
        new_id.erase(new_id.end() - 1);
    }

    // cout << new_id << endl;

    if (new_id.size() == 0) {
        new_id += 'a';
    }
    // cout << new_id << endl;

    while (new_id.size() < 3) {
        new_id += new_id[new_id.size() - 1];
    }

    // cout << " size : " << new_id.size() << endl;
    // cout << new_id << endl;

    answer = new_id;

    return answer;
}