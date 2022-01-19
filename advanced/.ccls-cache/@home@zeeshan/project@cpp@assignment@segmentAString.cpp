

/*
 *
 * Given an input string and a dictionary of words, find out if the input string can be segmented into a 
 * space-separated sequence of dictionary words. 
 * Ex: "bedbathandbeyond" would be "bed bath and beyond" which are all dictionary words.
 *
 */
 

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>


bool _getWordsRoutine(int i, std::string const & s, std::unordered_set<std::string> const & validWords, std::vector<std::string> & words)
{
	if(i >= s.size())
		return true;

	std::string tmp="";
	for(; i<s.size(); i++)
	{
		tmp.append(1, s[i]);
		if(validWords.find(tmp) != validWords.end())
		{
			if(_getWordsRoutine(i+1, s, validWords, words))
			{
				words.push_back(tmp);
				return true;
			}
		}
	}
	return false;
}

std::vector<std::string> getWords(const std::string & s, const std::unordered_set<std::string> & validWords)
{
	std::vector<std::string> words;
	_getWordsRoutine(0, s, validWords, words);
	std::reverse(words.begin(),words.end());
	return words;
}

int main()
{
	std::string s = "bedbathandbeyond";

	std::unordered_set<std::string>validWords = { "be", "bed", "bath", "a", "an", "and", "beyond", "on" };
	auto words = getWords(s,validWords);
	
	if(words.empty())
		std::cout << "Not possible.\n";
	else
	{
		for(auto x : words)
			std::cout << x << "\n";
	}

}
