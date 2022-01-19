
#include <iostream>
#include "logger.hpp"

int main()
{
    std::cout << "hello\n";

    auto & logger = Logger::instance("main.log");
    logger.info("started");
}
