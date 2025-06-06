#include <iostream>
#include <stack>
using namespace std;

int n;
stack<pair<int,int>> st;

int total_score = 0; // 총 점수

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++){

        int cmd;
        cin >> cmd;

        if( cmd == 1) {

            int score, time;
            cin >> score >> time;

            time--;

            if(time <= 0){
                total_score += score; // 시간 소모가 0 이하인 경우 점수 추가
            }
            else{
                st.push({score, time}); // 스택에 점수와 남은 시간을 저장
            }

        }
        else{

            if(st.empty()) continue; // 스택이 비어있으면 무시

            auto top = st.top();
            st.pop(); // 스택에서 가장 위의 요소를 꺼냄

            int score = top.first;
            int time = top.second;

            time--; // 남은 시간 감소

            if(time <= 0){
                total_score += score; // 시간 소모가 0 이하인 경우 점수 추가
            }
            else{
                st.push({score, time}); // 남은 시간이 있다면 다시 스택에 저장
            }
        }

    }


    cout << total_score << "\n"; // 총 점수 출력
    return 0;

}




