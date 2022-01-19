

#include <iostream>

struct semi_regular_t
{
    int a;

    semi_regular_t(int a) :a{a}
    {
        std::cout << "In ctor\n";
    };

    ~semi_regular_t()
    {
        std::cout << "In dtor\n";
    }

    semi_regular_t(semi_regular_t const & t)
    {
        std::cout << "In copy ctor\n";
        this->a = t.a;
    }
};

semi_regular_t foo()
{
    auto temp = semi_regular_t{2};
    return std::cout<<"hello\n", semi_regular_t{temp};
}

int main()
{
    foo();
}
