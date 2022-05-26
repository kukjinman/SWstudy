#include "../ThreadPool_class/ThreadPool.h"
#include <iostream>
#include <memory>
// using namespace std;

int main()
{
    std::cout << "Unit test main start" << std::endl;
    std::shared_ptr<ThreadPool::ThreadPool> m_ThreadPool;
    m_ThreadPool = std::make_shared<ThreadPool::ThreadPool>(10);

    
    return 0;
}