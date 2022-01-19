

#include <iostream>
#include <vector>


int main()
{

    std::vector<int> nums;


    int a;
    std::cin >> a;
    nums.push_back(a);
    std::cin >> a;
    nums.push_back(a);



    std::cout << nums[0] << std::endl;
    std::cout << nums[1] << std::endl;
}
