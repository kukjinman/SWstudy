#include "../ThreadPool_class/ThreadPool.h"
#include "../Linux_CPU_Checker/cpuChecker.h"

#include <iostream>
#include <memory>
using namespace std;


// Unit Test
// A,B,C,D에대한 request Task가 각각의 다른 완료시간을 가지고 있다.

//<요구사항 1>
// Main Thread 단독에서 A,B,C,D에 대한 1회씩 걸리는 시간을 측정해야한다.
// Thread Pool을 반영하고 A,B,C,D에 대한 1회씩 걸리는 시간을 측정해야한다.

//<요구사항 2>
// stopThreadPool의 구현을 확인하는 test case를 제공해야 한다.

//<요구사항 3>
// request가 들어오는 순서에 대해서는 request function이 현재 running중일때 무시되도록하는 case가 2번 이상 들어가야한다.
// 중복된 request가 무시되는 case에 대하여 출력으로 결과를 표시해야 한다.

//<요구사항 4>
// cpuChecker.h의 API를 사용하여 main thread에서의 CPU사용률과 Thread Pool에서의 사용률을 시간 based로 결과 보고를 해야한다.


void requestTask_A()
{
    string buf = "";

    for (int i = 0; i < 300000; i++) {
        buf = to_string(i);
    }
}

void requestTask_B()
{
    string buf = "";

    for (int i = 0; i < 1500000; i++) {
        buf = to_string(i);
    }
}

void requestTask_C()
{
    string buf = "";

    for (int i = 0; i < 2800000; i++) {
        buf = to_string(i);
    }
}

void requestTask_D()
{
    string buf = "";

    for (int i = 0; i < 5200000; i++) {
        buf = to_string(i);
    }
}

int main()
{
    cout << "Unit test main start" << endl;

    return 0;
}