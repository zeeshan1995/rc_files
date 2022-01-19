
#pragma once
#include <cstddef>
#include <ostream>

class char_str
{
    public:
        char_str() : char_str{""} {}
        char_str(const char *);

        ~char_str();

        char_str(char_str const &);
        char_str& operator=(char_str);

        char_str(char_str &&);
        char_str& operator=(char_str &&);

        void swap(char_str &);

        char& operator[](std::size_t index) { return *(_str + index); }
        const char & operator[](std::size_t index) const { return const_cast<char_str&>(*this)[index]; }

        std::size_t size() const {return _size;}

        char* c_str() { return _str;}
        const char* c_str() const {return const_cast<char_str&>(*this).c_str();}

    private:
        char * _str;
        std::size_t _size;
};

auto operator << (std::ostream & out, char_str const & str)
    -> std::ostream&;
