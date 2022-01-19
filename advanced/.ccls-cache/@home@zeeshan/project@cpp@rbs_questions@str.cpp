

#include <iostream>

int main()
{
    /*
    std::string a = "first";
    std::string b = "second";

    auto & a_ref = a;
    auto & b_ref = b;

    auto * a_ptr = &a;
    auto * b_ptr = &b;

    std::cout << a << " " << b <<"\n";
    std::cout << a_ref << " " << b_ref << " " << *a_ptr << " " << *b_ptr << "\n";

    std::swap(a, b);

    std::cout << a << " " << b <<"\n";
    std::cout << a_ref << " " << b_ref << " " << *a_ptr << " " << *b_ptr << "\n";

    a.swap(b);

    std::cout << a << " " << b <<"\n";
    std::cout << a_ref << " " << b_ref << " " << *a_ptr << " " << *b_ptr << "\n";
    */
    const std::string a = "my name is apple";
    //a.erase(a.end(), a.begin()+4);
    std::cout << a << "\n";
    *a.begin() = 'S';
    std::cout << a << "\n";
}
