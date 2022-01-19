
#include "conjunction.hpp"

#include <iomanip>
#include <iostream>

bool f1(int){return true;}
bool f2(int){return false;}

int main()
{
    int a = 23;
    auto p1 = [](int){return true;};
    auto p2 = [](int){return false;};

    auto p3 = [&a](int){return true;};
    auto p4 = [&a](int){return false;};


    int b = 42;

    std::cout << std::boolalpha << conjunction(b, f1) << std::endl;
    std::cout << std::boolalpha << conjunction(b, p1) << std::endl;
    std::cout << std::boolalpha << conjunction(b, p3) << std::endl;


    std::cout << std::boolalpha << conjunction(b, f1, p1) << std::endl;
    std::cout << std::boolalpha << conjunction(b, f1, p3) << std::endl;

    std::cout << std::boolalpha << conjunction(b, p1, p3) << std::endl;
}

