#include <iostream>
#include <string>
using namespace std;

//입력받는부분
string input;

void InputData()
{

    cin >> input;
}
int main()
{

    InputData();

    int ans = 0;

    // 숫자 받아올 버퍼입니다.
    string temp;
    //처음 마이너스 부호 구분 flag입니다.
    bool FirstMinusFlag = false;

    for (int i = 0; i <= input.size(); i++) {

        if (input[i] == '-' || input[i] == '+' || input[i] == '\0') {

            if (FirstMinusFlag == true) {
                //stoi로 string to int 형변형입니다.
                ans -= stoi(temp);

            } else {
                ans += stoi(temp);
            }

            // ans에 temp값 처리된 후 다음 숫자를 받아오기 위해 clear합니다.
            temp.clear();
            if (input[i] == '-') {
                //처음 minus 부호 시에만 타는 if문입니다.
                FirstMinusFlag = true;
            }

            continue;
        }

        //char 한숫자씩 string에 담습니다. stoi로 위에서 형변형을 함으로 10진수 처리 안해줘도 됩니다.
        temp += input[i];

        //Debugging Code
        // cout<<"i :"<<i<<"temp :"<<temp<<endl;

        //cout<<"i :"<<i<< "ans: "<<ans<<endl;
    }
    cout << ans << endl;

    return 0;
}