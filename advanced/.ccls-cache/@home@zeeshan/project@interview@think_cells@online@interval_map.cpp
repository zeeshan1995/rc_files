#include <map>
#include <limits>
#include <iostream>

template<typename K, typename V>
class interval_map {
public:
	std::map<K,V> m_map;

    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        //m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
        m_map.insert(m_map.end(),std::make_pair(0,val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
// INSERT YOUR SOLUTION HERE
        if( not (keyBegin < keyEnd))
            return;
        auto [it, inserted] = m_map.try_emplace(keyBegin, val);
        auto prev = inserted ? std::prev(it)->second : it->second;
        if(not inserted)
            it->second = val;

        //std::cout << *this;

        auto upper_itr = m_map.upper_bound(keyEnd);
        auto prev_itr  = std::prev(upper_itr);

        //std::cout << upper_itr->first << " " << prev_itr->first << "\n";
        if(prev_itr != it)
        {
            if(prev_itr->first < keyEnd)
            {
                prev_itr = m_map.emplace_hint(upper_itr, keyEnd, prev_itr->second);
                m_map.erase(std::next(it), prev_itr);//it and new_itr may have same value
            }
            else
            {
                m_map.erase(std::next(it), prev_itr);
            }
        }
        else
        {
            prev_itr = m_map.emplace_hint(upper_itr, keyEnd, prev);
        }

        std::cout << "Insertion done\n";

        //delete begin
        if(it != m_map.begin())
        {
            auto begin_prev = std::prev(it);
            if(it->second == begin_prev->second)
                m_map.erase(it);
            it = begin_prev
        }
        auto end_next = std::next(prev_itr);
        if(end_next->second == prev_itr->second)
            m_map.erase(prev_itr);
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
    friend std::ostream & operator <<(std::ostream & out, interval_map const & imap)
    {
        out << "------------------\n";
        for(auto const & p : imap.m_map)
            out << p.first << " " << p.second << "\n";
        out << "------------------\n";
        return out;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.

//Complete inside;
void test1(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,35,'Z');
    map_copy[23] = 'Z';
    map_copy[35] = 'B';

    std::cout << std::boolalpha << "test1=>" << (map_copy == imap.m_map) << "\n";
}

//Single cross
void test2(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,45,'Z');
    map_copy[23] = 'Z';
    map_copy[45] = map_copy[40];
    map_copy.erase(40);

    std::cout << std::boolalpha << "test2=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
//Multiple Cross
void test3(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,65,'Z');
    map_copy[23] = 'Z';
    map_copy[65] = map_copy[60];
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);

    std::cout << std::boolalpha << "test2=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}

//Complete inside left same;
void test4(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,40,'Z');
    map_copy[23] = 'Z';

    std::cout << std::boolalpha << "test1=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
//Single cross left same
void test5(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,50,'Z');
    map_copy[23] = 'Z';
    map_copy.erase(40);

    std::cout << std::boolalpha << "test2=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
//Multiple Cross
void test6(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,70,'Z');
    map_copy[23] = 'Z';
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);

    std::cout << std::boolalpha << "test2=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
//Multiple Cross
void test7(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,300,'Z');
    map_copy[23] = 'Z';
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);
    map_copy.erase(200);
    map_copy.erase(201);
    map_copy.erase(203);
    map_copy[300] = 'A';

    std::cout << std::boolalpha << "test7=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}

//Multiple Cross end is same
void test8(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,65,'F');
    map_copy[23] = 'F';
    map_copy[65] = map_copy[60];
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);

    std::cout << std::boolalpha << "test8=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test9(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,65,'E');
    map_copy[23] = 'E';
    map_copy[65] = map_copy[60];
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);

    std::cout << std::boolalpha << "test9=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}

void test10(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,65,'B');
    map_copy[23] = 'E';
    map_copy[65] = map_copy[60];
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);

    std::cout << std::boolalpha << "test9=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}

void test11(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,65,'C');
    map_copy[23] = 'E';
    map_copy[65] = map_copy[60];
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);

    std::cout << std::boolalpha << "test9=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
#if 0
#endif
int main()
{
    interval_map<int, char> imap{'A'};
    auto & _map = imap.m_map;

    _map[20] = 'B';
    _map[40] = 'C';
    _map[50] = 'D';
    _map[60] = 'E';
    _map[70] = 'F';
    _map[100] = 'G';

    _map[200] = 'A';
    _map[201] = 'B';
    _map[203] = 'A';

    auto map_copy = imap.m_map;

    //std::cout << imap << "\n";
#if 0
    test1(imap, map_copy);
    test2(imap, map_copy);
    test3(imap, map_copy);
    test4(imap, map_copy);
    test5(imap, map_copy);
    test6(imap, map_copy);
    test7(imap, map_copy);
    test8(imap, map_copy);
    test10(imap, map_copy);
#endif
    //test9(imap, map_copy);
    test11(imap, map_copy);
}
