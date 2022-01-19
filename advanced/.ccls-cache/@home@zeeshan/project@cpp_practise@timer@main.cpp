

#include <iostream>
#include <thread>
#include <chrono>


void hello()
{
    for(long long i=0; i<1e9; ++i)
        std::cout << "[world]\n";
}

template <typename Callable>
void worker(Callable call_on_interval, int milliseconds, bool call_once)
{
    do
    {
        std::this_thread::sleep_for(std::chrono::milliseconds{milliseconds});
        call_on_interval();
    }while(not call_once);
}

template <typename Callable>
void set_timeout(Callable call_on_interval, int milliseconds)
{
    std::thread{worker<Callable>
               ,call_on_interval
               ,milliseconds
               ,true}.detach();
}

template <typename Callable>
void set_interval(Callable call_on_interval, int milliseconds)
{
    std::thread{worker<Callable>
               ,call_on_interval
               ,milliseconds
               ,false}.detach();
}

int main()
{
    set_timeout([](){std::cout << "[world]\n";}, 1);
    set_interval([](){std::cout << "[star]\n";}, 1);
    for(long long i=0; i<1e9; ++i)
        std::cout << "[hello]\n";
}
