

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>

const int SIZE = 1e8;
int main()
{
	std::vector<int>nums(SIZE);
	std::iota(nums.begin(), nums.end(), 0);
	std::vector<int>other(SIZE);
	std::iota(other.begin(), other.end(), 0);

	std::vector<long long>res(SIZE);
	auto start = std::chrono::high_resolution_clock::now(); 
	#pragma simd
	for(int i=0; i<nums.size(); ++i)
		res[i] = nums[i] * other[i];
	auto stop = std::chrono::high_resolution_clock::now(); 

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Time taken by function: "
			         << duration.count() << " microseconds" << std::endl;
		  
}
