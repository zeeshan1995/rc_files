
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <tuple>

std::default_random_engine get_engine()
{
	std::random_device rd{};
	std::default_random_engine e{rd()};
	return e;
}

int numberOfTestCases(int min, int max)
{
	auto engine = get_engine();
	std::uniform_int_distribution<unsigned> distribution(min,max);
	return distribution(engine);
}

std::vector<std::tuple<int, int, char>> getTestCases(int t, int min, int max)
{
	auto engine = get_engine();
	std::uniform_int_distribution<unsigned> distKey(min,max);
	std::uniform_int_distribution<char> distValue('A','Z');

	std::vector<std::tuple<int, int, char>> testCases;
	while(t--)
	{
		int begin = distKey(engine), end(distKey(engine));
		char value = distValue(engine);
		testCases.push_back(std::make_tuple(begin, end, value));
	}

	return testCases;
}

const int MAX_KEY = 1000;
int main(int argc, char ** argv)
{
	
	freopen(argv[1],"w",stdout);
	auto t = numberOfTestCases(60,100);
	auto testCases = getTestCases(t,0,MAX_KEY);

	std::cout << MAX_KEY << " " << t <<"\n";
	for(auto x : testCases)
	{
		std::cout << std::get<0>(x) << " "<< std::get<1>(x) << " "<< std::get<2>(x) << "\n";
	}
}
