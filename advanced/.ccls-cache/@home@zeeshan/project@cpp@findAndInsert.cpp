

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

template<typename C, typename V>

void findAndInsert(C& container, // in container, find

		const V& targetVal, // first occurrence

		const V& insertVal) // of targetVal, then

{ // insert insertVal

	using std::cbegin; // there

	using std::cend;

	auto it = std::find(cbegin(container), // non-member cbegin

			cend(container), // non-member cend

			targetVal);

	container.insert(it, insertVal);

}


int main()
{
	std::vector<int> nums = {1,2,3,4,5};
	findAndInsert(nums, "sumi","name");
}
