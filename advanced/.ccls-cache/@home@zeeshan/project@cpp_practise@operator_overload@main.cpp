

#include "header/person.hpp"
#include <iostream>

namespace other
{
    bool operator == (orignal::person const & a
                     ,orignal::person const & b)
    {
        return a.name == b.name;
    }
    void foo()
    {
        orignal::person a{"zeeshan", 12};
        orignal::person b{"zeeshan", 12};

        std::cout << std::boolalpha << (a == b ) << "\n";
    }
}
int main()
{
}
