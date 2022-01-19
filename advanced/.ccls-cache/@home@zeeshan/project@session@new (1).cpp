#include <iostream>

int main()
{   int a = 0;
    int b = 1;
    int n,c;
    
    std::cout << "Enter the number of elements in the series:";
    std::cin >> n;
    
     std::cout << a << "," << b << ",";
    
    
     //assignment operator
     //
     //fibonacci series
    for(int i=2;i<n;++i)
    {
        c = a + b;
        std::cout << c << ",";
        a = b;
        b = c;
    }
    std::cout << std::endl;
}
