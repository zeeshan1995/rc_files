

#include <iostream>


int main()
{

    int nums[1000]; // array of int of size 4
    float f[55];
    double d[4646];
    long ddd[6464];

    char c[344];
    std::string names[5454];

    int i;
    std::cin >> i;

    /*
    std::cout << "number for index 0 => ";
    std::cin >> nums[0];
    std::cout << nums[0] << std::endl;

    std::cout << "number for index 1 => ";
    std::cin >> nums[1];
    std::cout << nums[1] << std::endl;

    std::cout << "number for index 2 => ";
    std::cin >> nums[2];
    std::cout << nums[2] << std::endl;

    std::cout << "number for index 3 => ";
    std::cin >> nums[3];
    std::cout << nums[3] << std::endl;
    */

    for(int i=0; i<4; ++i)
    {
        std::cout << "number of index " << i;
        std::cin >> nums[i];
        std::cout << nums[i] << std::endl;
    }
}

