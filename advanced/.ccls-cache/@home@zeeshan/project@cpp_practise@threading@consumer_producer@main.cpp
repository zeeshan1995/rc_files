

#include <vector>
#include <queue>
#include <iostream>
#include <functional>

#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

void producer(std::queue<int>         & nums
             ,std::mutex              & mut
             ,std::condition_variable & cond)
{
    std::cout << __FUNCTION__ << "\n";
    int i = 0;
    while(true)
    {
        if(i&1)
            std::this_thread::sleep_for(std::chrono::seconds(2));
        std::unique_lock<std::mutex> lock{mut};
        nums.push(i);
        cond.notify_one();
        ++i;
    }
}

void consumer(std::queue<int>         & nums
             ,std::mutex              & mut
             ,std::condition_variable & cond)
{
    std::cout << __FUNCTION__ << "\n";
    while(true)
    {
        std::unique_lock<std::mutex> lock{mut};
        cond.wait(lock);
        nums.pop();
    }
}

int main()
{
    std::cout << "Hello World\n";

    std::queue<int> q;
    std::mutex mut;
    std::condition_variable cond;
    auto p_thread = std::thread{producer
                               ,std::ref(q)
                               ,std::ref(mut)
                               ,std::ref(cond)};
    std::this_thread::sleep_for(std::chrono::seconds(2));
#if 1

    auto c_thread = std::thread{consumer
                               ,std::ref(q)
                               ,std::ref(mut)
                               ,std::ref(cond)};
    p_thread.join();
    c_thread.join();
#endif
}
