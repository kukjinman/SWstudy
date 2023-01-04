#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct File {
    string head, origin;
    int idx, num;
};
vector<File> file_vec;

bool isComp(File f1, File f2)
{
    if (f1.head < f2.head) { // HEAD 기준 사전 순
        return true;
    } else if (f1.head == f2.head) {
        if (f1.num < f2.num) { // NUMBER 기준 순
            return true;
        } else if (f1.num == f2.num) {
            if (f1.idx < f2.idx)
                return true; // 인덱스 기준 순
            else
                return false;
        } else
            return false;
    } else
        return false;
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    for (int i = 0; i < files.size(); i++) { // HEAD, NUMBER
        File f;
        int num_st_idx = 0, num_cnt = 0, tail_st_idx = 0;

        // HEAD 찾기
        string temp_head = "";
        for (int j = 0; j < files[i].size(); j++) {
            if (files[i][j] >= '0' && files[i][j] <= '9') {
                num_st_idx = j;
                break;
            } else if (files[i][j] >= 'A' && files[i][j] <= 'Z')
                temp_head.push_back(files[i][j] + 32);
            else
                temp_head.push_back(files[i][j]);
        }

        // NUMBER 찾기
        string temp_num = "";
        for (int j = num_st_idx; j < files[i].size(); j++) {
            if (files[i][j] < '0' || files[i][j] > '9') {
                tail_st_idx = j;
                break;
            } else if (num_cnt == 5) {
                tail_st_idx = j;
                break;
            } else {
                temp_num.push_back(files[i][j]);
                num_cnt++;
            }
        }

        // 구조체 생성
        f.origin = files[i];
        f.head = temp_head;
        f.num = atoi(temp_num.c_str());
        f.idx = i;
        // 벡터에 넣기
        file_vec.push_back(f);
    }

    sort(file_vec.begin(), file_vec.end(), isComp);

    for (int i = 0; i < file_vec.size(); i++) {
        answer.push_back(file_vec[i].origin);
    }
    return answer;
}
