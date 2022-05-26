#include "../ThreadPool_class/ThreadPool.h"
#include <iostream>
#include <memory>
using namespace std;

// Integration Test
// A,B,C,D에대한 request Task가 각각의 task를 수행하는 delay를 가지고 있다.
// ThreadPool의 최대 수를 조절하여 CPU의 점유율과 memory usage의 변화량을 기록한다.
// A,B,C,D의 request Task는 TaskQueue를 만들어서 request가 온 순차적으로 실행되게 구현한다.
// request가 들어오는 순서에 대해서는 request function이 현재 running중일때 무시되도록하는 case가 2번 이상 들어가야한다.
// request TaskQueue에 넣는 요청 task 양은 1분 +-5초만큼 test가 가능하도록 구현을 한다.

void requestTask_A()
{
    sleep(1);
}

void requestTask_B()
{
    sleep(2);
}

void requestTask_C()
{
    sleep(3);
}

void requestTask_D()
{
    sleep(4);
}

int main()
{
    std::cout << "Integration test main start" << std::endl;
    std::shared_ptr<ThreadPool::ThreadPool> m_ThreadPool;
    m_ThreadPool = std::make_shared<ThreadPool::ThreadPool>(2);

    return 0;
}