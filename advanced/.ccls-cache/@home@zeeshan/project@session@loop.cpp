

#include <iostream>



int main()
{
    //loop --> repetation
    

    //for, while, do while
    //
    //
    //3 6 9 12 15 18 21 27 30
    //
    //4 8 12 16 20 24 28 32 26 40

    int sum = 0;

    for(int i=0; i<3; ++i)
    {
        int a;
        std::cin >> a;
        sum = sum + a;
    }

    std::cout << sum << std::endl;
}
