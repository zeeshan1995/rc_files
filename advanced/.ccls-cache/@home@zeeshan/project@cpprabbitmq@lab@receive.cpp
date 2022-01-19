#include <connection.hpp>
#include <channel.hpp>
#include <thread>
#include <chrono>

int main()
{
    auto && conn = connection{"localhost", 5672};
    auto && channel1 = channel(conn);
    channel1.declare_queue("queue_from_cpp");
    //channel1.basic_publish("", "queue_from_cpp", "test_message");

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);
    std::cout << "here\n";
    //channel1.receive();
}