// Example program
#include <iostream>
#include <string>

using namespace std;
int main()
{

    //결과값:최소 기능 사용 횟수
    int Acount = 0;
    int Bcount = 0;
    int Ccount = 0;

    // 전자레인지 도구(단위:second)
    int A = 300;
    int B = 60;
    int C = 10;

    //요리시간 T
    int T = 0;

    //불가능 여부 체크 flag
    bool impossibleFlag = false;

    cin >> T;

    while (T != 0) {

        if (T >= A) {
            //A기능 사용 나눈 몫
            Acount = T / A;
            //A기능 사용 후 나머지
            T = T % A;

        } else if (T >= B) {

            // B기능 사용 나눈 몫
            Bcount = T / B;
            // B기능 사용 후 나머지
            T = T % B;

        } else if (T >= C) {

            // C기능 사용 나눈 몫
            Ccount = T / C;
            // C기능 사용 후 나머지
            T = T % C;
        } else {

            if (T != 0)

            {
                // A,B,C로 계속 나눴지만 나머지가 남아
                // T 를 나누기 불가능한 경우
                impossibleFlag = true;
                break;
            }
        }
    }

    //T 나누기 불가능 여부 체크 후
    //각각 결과 값 출력 분기문
    if (impossibleFlag == true) {
        cout << -1 << endl;
    } else {
        cout << Acount << " " << Bcount << " " << Ccount << endl;
    }
}