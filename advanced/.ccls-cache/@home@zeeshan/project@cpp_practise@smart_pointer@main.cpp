

#include "unique_ptr.hpp"
#include <iostream>


void foo(unique_ptr<int> p)
{
    //auto && x = std::move(p);

    //std::cout << x.get() << "\n";
    std::cout << p.get() << "\n";

    //x.reset();
    //std::cout << x.get() << "\n";
    //std::cout << p.get() << "\n";

    std::cout << &p << "\n";
    //std::cout << &x << "\n";
}
int main()
{
    unique_ptr<int> p{new int{1}};

    std::cout << p.get() << "\n";

    std::cout << &p << "\n";

#if 0
    std::cout << "===========================\n";
    foo(std::move(p));
    std::cout << "====================\n";

    std::cout << bool(p) << "\n";
    std::cout << p.get() << "\n";
#endif

    std::cout << "=====================\n";
    {
        auto x = unique_ptr<int>{new int{2}};
        std::cout << "Done\n";
        x = std::move(p);
        std::cout << "Done move\n";
        std::cout << *p << "\n";
        std::cout << *x << "\n";
    }
    std::cout << "out\n";
}

