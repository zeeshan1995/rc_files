

#include <iostream>

int main()
{
    int a = 23;
    int &n = a;
    int &p = n;
    int * x = &p;

    std::cout << &a << " " << &n << "\n";
    std::cout << &p <<"\n";
    std::cout << x << " " << *x <<"\n";
}
