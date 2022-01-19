

#include <iostream>

class Foo
{
    public:
        Foo() = default;
        Foo(int a) : a{a} {std::cout << "Foo Paramiterised ctr\n";}
        Foo(Foo const & other) : a{other.a} {std::cout << "Foo Copy ctr\n";}
        Foo(Foo && other) : a{other.a} {std::cout << "Foo  Move ctr\n";}

    private:
        int a;
};
class Bar : public Foo
{
    public:
        Bar() = default;
        Bar(int a) : Foo{a} {std::cout << "Bar Paramiterised ctr\n";}
        Bar(Bar const & other) : Foo{other} {std::cout << "Bar Copy ctr\n";}
        Bar(Bar && other) : Foo{other} {std::cout << "Bar Move ctr\n";}
};


int main()
{
    auto b = std::move(Bar{23});
}
