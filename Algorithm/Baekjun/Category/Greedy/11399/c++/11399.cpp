#include <iostream>
#include <list>
using namespace std;

int N;
int Wtime[1000];
int Wtime_sorted[1000];

int main()
{

    //각 사람의 걸리는 시간을 list로 잡았습니다.
    list<int> mylist;

    //N명의 값을 받습니다.
    cin >> N;

    //N명 각각의 걸리는 시간을 받습니다.
    for (int i = 0; i < N; i++) {
        cin >> Wtime[i];
        //list에도 담아줍니다.
        mylist.push_back(Wtime[i]);
    }

    //list 오름차순으로 sort 합니다.
    mylist.sort();

    for (int i = 0; i < N; i++) {

        //Wtime_sorted Array에 list front값을 가져옵니다.
        Wtime_sorted[i] = mylist.front();
        //담아둔 front값을 pop 하여 버립니다.
        mylist.pop_front();
    }

    int Sum = 0;

    for (int k = 0; k < N; k++) {
        //N명분 사람의 걸린 시간 반복합니다.
        for (int j = 0; j <= k; j++) {
            //0 ~ N-1번째 사람 앞사람의 걸린 시간 Sum에 더합니다.
            Sum += Wtime_sorted[j];
        }
    }

    cout << Sum << endl;

    return 0;
}
