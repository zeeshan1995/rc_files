#include <iostream>
class Foo
{
    public:
        Foo() = default;
        Foo(int a) : a{a} {}
        int get() {return a;}
    private:
        int a;
};
int main()
{
    auto a = Foo{23};
    auto b = std::move(a);
    std::cout << a.get() << " " << b.get() << "\n";
}
