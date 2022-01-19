

//#include "selector.hpp"

#include <iostream>

template <int N>
struct preference : preference<N+1> 
{
    preference()
    {
        std::cout << N << "\n";
    }
};

template<>
struct preference<25> {};


int main()
{
    preference<12> x;
    std::cout << "preference<12> done\n";

    preference<15> y;
    std::cout << "preference<15> done\n";

    preference<12> z;
    std::cout << "preference<12> done\n";

    static_assert(std::is_same<decltype(x), decltype(z)>::value, "Different type");
}

