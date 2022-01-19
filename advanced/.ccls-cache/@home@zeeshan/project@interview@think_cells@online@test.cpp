

#include "my_map.hpp"

#include <iostream>

class Key
{
    int a;

    public:
        Key(int a) : a{a} {}
        Key(Key const & k) : a{k.a} {}
        Key& operator=(Key other)
        {
            std::swap(a, other.a);
            return *this;
        }
        friend bool operator<(Key const & left, Key const & right)
        {
            return left.a < right.a;
        }
};

class Value
{
    char a;

    public:
        Value(char a) : a{a} {}
        Value(Value const & k) : a{k.a} {}
        friend bool operator==(Value const & left, Value const & right)
        {
            return left.a == right.a;
        }
};

int main()
{
    std::cout << "heelo\n";
    interval_map<Key, Value> _map{'A'};
    _map.assign(12, 100, 'A');
}
