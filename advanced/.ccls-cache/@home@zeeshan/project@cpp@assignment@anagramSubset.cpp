
/*
 * 
 * You are given set of strings, You have return anagrams subsets from it. 
 * An anagram set is that one where every string is an anagram of another string. 
 * If the subset contains only one string, don't include that in the result.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


std::vector<std::vector<std::string>> groupAnagram(std::vector<std::string> const & words)
{

	std::vector<std::vector<std::string>>subset;
	std::unordered_map<std::string, int> freq;

	for(auto x : words)
	{
		auto tmp=x;
		std::sort(tmp.begin(), tmp.end());
		if(freq.find(tmp)==freq.end())
		{
			freq[tmp] = subset.size();
			subset.push_back(std::vector<std::string>());
		}
		subset[freq[tmp]].push_back(x);
	}

	return subset;
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::string> words(n);

	for(auto & x : words)
		std::cin >> x;

	auto anagrams = groupAnagram(words);


	for(auto x : anagrams)
	{
		if(x.size()<2)
			continue;
		for(auto y : x)
			std::cout << y << " ";
		std::cout << "\n";
	}	
}
