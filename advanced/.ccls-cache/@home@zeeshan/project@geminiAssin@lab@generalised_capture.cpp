

#include <iostream>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> nums ={1,2,3,4,5};

	auto func = std::bind([](std::vector<int> const & nums){
			for(auto x : nums)
				std::cout << x << " ";
			endl(std::cout);}, std::move(nums));

	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);

	func();
	func();
	for(auto x : nums)
		std::cout << x << " ";
	std::cout << "\n";
}
