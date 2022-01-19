
#pragma once

#include <string>

namespace orignal
{
    struct person
    {
        std::string name;
        int age;
    };

    bool operator == (person const & a
                     ,person const & b)
    {
        return a.name == b.name;
    }
}
