

/*
 *
 * Given an input string and a dictionary of words, find out if the input string can be segmented into a 
 * space-separated sequence of dictionary words. 
 * Ex: "bedbathandbeyond" would be "bed bath and beyond" which are all dictionary words.
 *
 */
 

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>


bool _getWordsRoutine(int i, std::string const & s, std::unordered_map<std::string,int> const & dict , std::vector<std::string> & words)
{
	if(i >= s.size())
		return true;

	std::string tmp="";
	for(; i<s.size(); i++)
	{
		tmp.append(1, s[i]);
		if(dict.find(tmp) != dict.end())
		{
			if(_getWordsRoutine(i+1, s, dict, words))
			{
				words.push_back(tmp);
				return true;
			}
		}
	}
	return false;
}


std::unordered_map<std::string, int> _vectorToMap(std::vector<std::string> const & dict)
{
	std::unordered_map<std::string, int> dictMap;
	for(auto x : dict)
		dictMap[x] = 1;
	return dictMap;
}

std::vector<std::string> getWords(const std::string & s, const std::vector<std::string> & dict)
{
	std::vector<std::string> words;
	_getWordsRoutine(0, s, _vectorToMap(dict), words);
	std::reverse(words.begin(),words.end());
	return words;
}

int main()
{
	std::string s = "bedbathandbeyond";

	std::vector<std::string>dict = { "be", "bed", "bath", "a", "an", "and", "beyond", "on" };

	auto words = getWords(s,dict);
	
	if(words.empty())
		std::cout << "Not possible.\n";
	else
	{
		for(auto x : words)
			std::cout << x << "\n";
	}

}
