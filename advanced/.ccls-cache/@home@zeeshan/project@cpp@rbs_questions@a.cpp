

#include <iostream>

int main()
{
    long long a = 20;
    const int & n = a;
    a = a++ * a*2;
    std::cout << a << " " << n <<"\n";
}
