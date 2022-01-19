#pragma once

#include <string>

class person
{
    public:
        std::string get_name() const { return _name;}
        person(std::string name) : _name{name} {}
    private:
        std::string _name;
};
