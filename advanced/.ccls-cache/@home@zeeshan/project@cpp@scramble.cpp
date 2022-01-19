/*
 *
 * You are given a scrambled input sentence. Each word is scrambled independently, and the results are concatenated. So: 
 *
 * 'hello to the world' 
 * might become: 
 * 'elhloothtedrowl' 
 *
 * You have a dictionary with all words in it. Unscramble the sentence.
 *
 */

#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<int>hashCode = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,
		67,71,73,79,83,89,97,101};

	std::string org = "hello to the world", s = "elhloothtedrowl";
	std::vector<int>hash;

	int n = 1;
	for(auto x : org)
	{
		if(x==' ')
		{
			hash.push_back(n);
			n=1;
		}
		else
			n*=hashCode[x-'a'];
	}

	solve(0,s,
}
