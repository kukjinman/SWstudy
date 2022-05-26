#include "ThreadPool.h"

namespace ThreadPool {

//조건1) 같은 이름의 request function name이 들어오면, 현재 다른 thread에서 해당 task를 처리중 일 시 무시하도록 구현해야합니다.
//조건2) EMMA가 종료 될 시, 해당 thread pool의 자원도 정리되는 stopThreadPool API를 구현해야 합니다.

ThreadPool::ThreadPool(size_t num_threads)
    : num_threads_(num_threads)
    , stop_all(false)
{
    worker_threads_.reserve(num_threads_);
    for (size_t i = 0; i < num_threads_; ++i) {
        worker_threads_.emplace_back([this]() { this->WorkerThread(); });
    }
}

void ThreadPool::WorkerThread()
{
    while (true) {
        std::unique_lock<std::mutex> lock(m_job_q_);
        cv_job_q_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
        if (stop_all && this->jobs_.empty()) {
            return;
        }

        // 맨 앞의 job 을 뺀다.
        std::function<void()> job = std::move(jobs_.front());
        jobs_.pop();
        lock.unlock();

        int threadId = gettid();
        printf("threadId : %d\n", threadId);

        // 해당 job 을 수행한다 :)
        job();
    }
}

ThreadPool::~ThreadPool()
{
    stop_all = true;
    cv_job_q_.notify_all();

    for (auto& t : worker_threads_) {
        t.join();
    }
}

void ThreadPool::EnqueueJob(std::function<void()> job)
{
    if (stop_all) {
        throw std::runtime_error("ThreadPool 사용 중지됨");
    }
    {
        std::lock_guard<std::mutex> lock(m_job_q_);
        jobs_.push(std::move(job));
    }
    cv_job_q_.notify_one();
}

}