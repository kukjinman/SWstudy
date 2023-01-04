#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int time_cal(string start, string end)
{
    int ret = 0;

    int s_hour = stoi(start.substr(0, start.find(":")));
    // cout << "s_hour : " << s_hour << endl;
    int s_min = stoi(start.substr(start.find(":") + 1));
    // cout << "s_min : " << s_min << endl;

    int e_hour = stoi(end.substr(0, end.find(":")));
    // cout << "e_hour : " << e_hour << endl;
    int e_min = stoi(end.substr(end.find(":") + 1));
    // cout << "e_min : " << e_min << endl;

    ret = (e_hour - s_hour) * 60 + e_min - s_min;

    // cout << "ret : " << ret << endl;
    return ret;
}

int charge_cal(vector<int>& fees_, int time_)
{
    int ret = 0;

    int basic_min = fees_[0];
    int basic_fee = fees_[1];
    int extra_min = fees_[2];
    int extra_fee = fees_[3];

    float tmp_time = time_;

    // cout << " b_fee : " << basic_fee << " b_min : " << basic_min << " e_fee : " << extra_fee << " e_min : " << extra_min << endl;

    if (tmp_time <= basic_min) {
        // cout << " tmp_time : " << tmp_time << " basic_min : " << basic_min << endl;

        ret = basic_fee;
        return ret;
    } else {
        // cout << " tmp_time : " << tmp_time << " basic_min : " << basic_min << endl;
        tmp_time -= basic_min;
        // cout << "[a] tmp_time : " << tmp_time << endl;
        ret += basic_fee;
        // cout << "[b] ceil : " << (tmp_time/extra_min) << endl;

        // cout << " ceil : " << (ceil(tmp_time/extra_min)) << endl;
        ret += (ceil(tmp_time / extra_min)) * extra_fee;
    }

    return ret;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;

    map<string, int> charge;
    map<string, string> car_list;

    for (auto s : records) {
        cout << " s : " << s << endl;

        int index = s.find(" ");
        string time = s.substr(0, index);
        string next_s = s.substr(index + 1);
        // cout << " time : " << time << endl;

        int next_idx = next_s.find(" ");
        string car = next_s.substr(0, next_idx);
        string enter = next_s.substr(next_idx + 1);
        // cout << " car : " << car << endl;
        // cout << " enter : " << enter << endl;

        if (enter == "IN") {
            car_list[car] = time;
        } else {
            // cout << "car : "<< car << " time : " << car_list[car] << endl;
            int minute = time_cal(car_list[car], time);
            charge[car] += minute;
            car_list.erase(car);
        }
    }

    //출차 하지 않은 차
    for (auto it : car_list) {
        // cout << "it :" << it.first << " second : " << it.second  << endl;
        string day_off_time = "23:59";
        int minute = time_cal(it.second, day_off_time);
        charge[it.first] += minute;
        car_list.erase(it.first);
    }

    for (auto it : charge) {
        // cout << "it :" << it.first << " second : " << it.second << endl;
        int temp = charge_cal(fees, it.second);
        answer.push_back(temp);
    }

    return answer;
}