#include <iostream>

int main()

{


    int nums[100];
    int a,i;


    std::cout << "How many numbers do you want to add?: ";
    std::cin >> a;

    int add = 0;

    std::cout << std::endl;
    if (a<=100)
    {
        for(int i=0; i<a; ++i)
        { 

            std::cout << " Enter your Number " << i << ":";
            std::cin >> nums[i];

            add= add + nums [i];

//            std::cout << sum << std::endl;

        }
        std::cout << std::endl;
        std::cout << "All the numbers added equals to:" << add <<std::endl;  
    }

    else
    { std::cout << " ERROR: Onky 100 numbers can be added " << std::endl; } 

}
