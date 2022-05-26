#include "../ThreadPool_class/ThreadPool.h"
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    cout << "Unit test main start" << endl;
    std::shared_ptr<ThreadPool::ThreadPool> m_ThreadPool;
    m_ThreadPool = std::make_shared<ThreadPool::ThreadPool>(10);

    cout << "=======================" << endl;
    cout << "  Input Test Number " << endl;
    cout << "=======================" << endl;

    cout << "Type q to exit" << endl;

    cout << "1 : " << endl;
    cout << "2 : " << endl;
    cout << "3 : " << endl;
    cout << "4 : " << endl;

    

    return 0;
}