#include <assert.h>
#include <map>
#include <limits>

template<class K, class V>
class interval_map {
    friend void IntervalMapTest();

private:
    std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.begin(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd). 
    // Overwrite previous values in this interval. 
    // Do not change values outside this interval.
    // Conforming to the C++ Standard Library conventions, the interval 
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval, 
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        // if keyBegin >= keyEnd, then do nothing
        if ( ! (keyBegin < keyEnd) )  {
            return;
        }
        // O(log(N))
        auto e = m_map.lower_bound(keyEnd);
        // O(1)
        auto endValue = e == m_map.end()
            ? m_map.rbegin()->second
            : keyEnd < e->first ? (--e)->second : e->second;

        // Amortized O(1)
        auto ex = m_map.insert(e, std::make_pair(keyEnd, endValue));
        // O(log(N))

		auto p = m_map.insert(std::make_pair(keyBegin, val));
		auto inserted = p.first;
		if ( ! p.second )  {
			inserted->second = val;
		}

        // compute the range to be deleted
        auto eraseBegin = inserted; ++eraseBegin;
        if ( inserted != m_map.begin() ) {
            auto prev = inserted; --prev;
            if ( prev->second == inserted->second ) {
                --eraseBegin;
            }
        }
        if ( inserted->second == ex->second ) {
			++ex;
        }

        // O(K) where K = std::distance(eraseBegin, ex);
        m_map.erase(eraseBegin, ex);

    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }

	const decltype(m_map.begin()) begin()
	{
		return m_map.begin();
	}
	
	const decltype(m_map.begin()) end()
	{
		return m_map.end();
	}
};

#include <iostream>
#include <fstream>
#include <vector>
#include <random>

std::default_random_engine get_engine()
{
	static std::random_device rd{};
	static std::default_random_engine e{rd()};
	return e;
}

int numberOfTestCases(int min, int max)
{
	auto engine = get_engine();
	std::uniform_int_distribution<unsigned> distribution(min,max);
	return distribution(engine);
}

std::tuple<int, int, char> getTestCase(int min, int max)
{
	static auto engine = get_engine();
	static std::uniform_int_distribution<unsigned> distKey(min,max);
	static std::uniform_int_distribution<char> distValue('A','Z');

	int begin = distKey(engine), end(distKey(engine));
	char value = distValue(engine);
	return std::make_tuple(begin, end, value);

}


void IntervalMapTest()
{
	interval_map<unsigned, char> imap('A');
	std::map<unsigned, char> testMap;

	int t = numberOfTestCases(60,100),  max=1000;

	for(int i=0; i<=max; i++)
		testMap[i] = 'A';


	std::vector<std::pair<unsigned, char>>mapData;	
	for(auto x : imap)
		mapData.push_back({x.first, x.second});

	while(t--)
	{
		auto testCase = getTestCase(0,max);
		int keyBegin = std::get<0>(testCase), keyEnd = std::get<1>(testCase);
		char value = std::get<2>(testCase);

		imap.assign(keyBegin, keyEnd, value);
		
		for(auto x = keyBegin; x < keyEnd; x++)
			testMap[x] = value;

		std::vector<std::pair<unsigned, char>>tmp;
		bool mismatch = false;
		for(auto x : imap)
		{
			tmp.push_back({x.first, x.second});
			if(x.second!=testMap[x.first])
				mismatch = true;
		}

		if(mismatch)
		{
			std::cout << "Error while assiging " << keyBegin << " " << keyEnd << " " << value << "\n";
			std::cout << "State of interval_map bere this assinment was:\n";
			for(auto x: mapData)
				std::cout << x.first << " " << x.second << "\n";
			std::cout <<"\nThe new error state is: \n";
			for(auto x: tmp)
				std::cout << x.first << " " << x.second << "\n";
			return;
		}
	}
	std::cout << "No Error found.\n";
}
// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a function IntervalMapTest() here that tests the
// functionality of the interval_map, for example using a map of unsigned int
// intervals to char.

int main() {

   IntervalMapTest();
}
