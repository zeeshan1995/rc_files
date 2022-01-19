

#include <vector>
#include <iostream>
#include "utils/type_name.hpp"


int main()
{
	std::vector<int>nums ={1,2,3,4};
	std::vector<bool>cond ={0,1,1,1};

	std::cout << type_name<decltype(nums[0])>() << "\n";
	std::cout << type_name<decltype(cond[0])>() << "\n";
}
