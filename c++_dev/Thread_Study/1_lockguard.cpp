#include <iostream>
#include <mutex>
#include <thread>

int g_i = 0;
std::mutex g_i_mutex; // protects g_i

void safe_increment()
{

    {
        // lock guard는 {}의 수행이 마쳐지면 unlock하여 mutex를 풀어준다.
        // {} 삭제 시 safe_increment()가 마칠 때 까지 lock하고 있음.
        const std::lock_guard<std::mutex> lock(g_i_mutex);
        ++g_i;

        std::cout << "g_i: " << g_i << "; in thread #"
                  << std::this_thread::get_id() << '\n';

        // g_i_mutex is automatically released when lock
        // goes out of scope
    }

    {
        const std::lock_guard<std::mutex> lock(g_i_mutex);
        ++g_i;

        std::cout << "g_i: " << g_i << "; in thread #"
                  << std::this_thread::get_id() << '\n';

        // g_i_mutex is automatically released when lock
        // goes out of scope
    }
}

int main()
{
    std::cout << "g_i: " << g_i << "; in main()\n";

    std::thread t1(safe_increment);
    std::thread t2(safe_increment);

    t1.join();
    t2.join();

    std::cout << "g_i: " << g_i << "; in main()\n";
}