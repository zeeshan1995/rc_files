
#include "char_str.hpp"
#include <cstring>
#include <cstddef>
#include <algorithm>
#include <ostream>
#include <iterator>

char_str::char_str(const char * str)
{
    _size = strlen(str);
    _str = new char[_size];
    strcpy(_str, str);
}

char_str::~char_str()
{
    if(_str)
        delete[] _str;
}

char_str::char_str(char_str const & right)
                 :_str{new char[right._size]}
                 ,_size{right._size}
{
    strcpy(_str, right._str);
}

char_str& char_str::operator=(char_str other)
{
    this->swap(other);
    return *this;
}

char_str::char_str(char_str && right)
                 :_str{right._str}
                 ,_size{right._size}
{
    right._str = nullptr;
    right._size = 0;
}

void char_str::swap(char_str & other)
{
    using std::swap;
    swap(_size, other._size);
    swap(_str, other._str);
}

auto operator << (std::ostream & out, char_str const & str)
    -> std::ostream&
{
    out << str.c_str();
    return out;
}
