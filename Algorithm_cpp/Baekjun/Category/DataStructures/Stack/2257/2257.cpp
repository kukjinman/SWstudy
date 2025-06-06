#include <iostream>
#include <stack>
#include <string>

using namespace std;

int ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    string str;

    cin >> str;

    for(int i = 0; i < str.size();i++){

        if(str[i] == 'H'){
            st.push(1);
        }
        else if(str[i] == 'C'){
            st.push(12);
        }
        else if(str[i] == 'O'){
            st.push(16);
        }
        else if(str[i] == '('){
            st.push(-1); // '('는 -1로 표시
        }
        else if(str[i] >= '2' && str[i] <= '9' )
        {
            int cur_num = str[i] - '0';
            int top = st.top();
            st.pop();
            st.push(top * cur_num); // 현재 숫자와 스택의 top을 곱해서 다시 스택에 넣음
        }
        else if(str[i] == ')'){

            int cur_sum = 0;
            while(!st.empty()){
                
                if(st.top() == -1){
                    st.pop(); // '('를 만나면 스택에서 제거
                    break; // '('를 만났으므로 반복문 종료
                }
                else{
                    cur_sum += st.top(); // ')'를 만나면 스택의 top 값을 ans에 더함
                    st.pop(); // 스택에서 top 값을 제거
                }
            }
            st.push(cur_sum); // 현재 합을 스택에 다시 넣음
        }



    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    cout << ans << "\n";
    return 0;

}




