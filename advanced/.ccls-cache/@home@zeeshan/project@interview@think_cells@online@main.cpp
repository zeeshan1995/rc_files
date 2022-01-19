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
        auto prev_value = inserted ? std::prev(it)->second : it->second;
        if(not inserted)
            it->second = val;
        if(it != m_map.begin())
        {
            auto begin_prev = std::prev(it);
            if(it->second == begin_prev->second)
            {
                m_map.erase(it);
                it = begin_prev;
            }
        }

        auto end_hint = m_map.lower_bound(keyEnd);
        if(end_hint == m_map.end() or keyEnd < end_hint->first)
        {
            auto prev_to_end = std::prev(end_hint);
            if(prev_to_end != it)
                prev_value = prev_to_end->second;
            end_hint = m_map.emplace_hint(end_hint, keyEnd, prev_value);
        }
        m_map.erase(std::next(it), end_hint);

        auto next_to_first = std::next(it);
        while(next_to_first != m_map.end() and it->second == next_to_first->second)
            next_to_first = m_map.erase(next_to_first);

#if 0
        auto upper_itr = m_map.upper_bound(keyEnd);
        auto prev_itr  = std::prev(upper_itr);
        m_map.erase(prev_itr, upper_itr);

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
        /*
        if(it != m_map.begin())
        {
            auto begin_prev = std::prev(it);
            if(it->second == begin_prev->second)
                m_map.erase(it);
            it = begin_prev
        }
        */
        auto end_next = std::next(prev_itr);
        if(end_next->second == prev_itr->second)
            m_map.erase(prev_itr);
#endif
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
    std::cout << imap << "\n";
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

    std::cout << std::boolalpha << "test3=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}

//Complete inside left same;
void test4(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,40,'Z');
    map_copy[23] = 'Z';

    std::cout << std::boolalpha << "test4=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
//Single cross left same
void test5(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,50,'Z');
    map_copy[23] = 'Z';
    map_copy.erase(40);

    std::cout << std::boolalpha << "test5=>" << (map_copy == imap.m_map) << "\n";
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

    std::cout << std::boolalpha << "test6=>" << (map_copy == imap.m_map) << "\n";
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
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);

    std::cout << std::boolalpha << "test9=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}

void test10(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,65,'B');
    map_copy[65] = map_copy[60];
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);

    std::cout << std::boolalpha << "test10=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}

void test11(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(23,65,'C');
    map_copy[23] = 'C';
    map_copy[65] = map_copy[60];
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);

    std::cout << std::boolalpha << "test11=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test12(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(200,201,'Z');
    map_copy[200] = 'Z';

    std::cout << std::boolalpha << "test12=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test13(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(200,203,'A');
    map_copy[200] = 'A';
    map_copy.erase(201);
    map_copy.erase(203);

    std::cout << std::boolalpha << "test13=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test14(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(503,610,'B');
    map_copy[503] = 'B';
    map_copy[610] = 'D';
    map_copy.erase(510);
    map_copy.erase(530);
    map_copy.erase(600);

    std::cout << std::boolalpha << "test9=>" << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test15(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(503,620,'B');
    map_copy[503] = 'B';
    map_copy.erase(510);
    map_copy.erase(530);
    map_copy.erase(600);
    map_copy.erase(620);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test16(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(410,610,'B');
    map_copy[610] = 'D';
    map_copy.erase(500);
    map_copy.erase(510);
    map_copy.erase(530);
    map_copy.erase(600);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test17(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(410,620,'B');
    map_copy.erase(500);
    map_copy.erase(510);
    map_copy.erase(530);
    map_copy.erase(600);
    map_copy.erase(620);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test18(interval_map<int, char> _imap, std::map<int, char> _map_copy)
{
    auto imap = interval_map<int, char>{'A'};
    std::map<int, char> map_copy;
    imap.assign(503,620,'B');
    map_copy[0] = 'A';
    map_copy[503] = 'B';
    map_copy[620] = 'A';

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test19(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(10,150,'C');
    map_copy[10] = 'C';
    map_copy[150] = 'G';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test20(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(10,150,'G');
    map_copy[10] = 'G';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test21(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(10,200,'B');
    map_copy[10] = 'B';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test22(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(10,201,'B');
    map_copy[10] = 'B';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);
    map_copy.erase(200);
    map_copy.erase(201);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test23(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(0,150,'C');
    map_copy[0] = 'C';
    map_copy[150] = 'G';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test24(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(0,150,'G');
    map_copy[0] = 'G';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test25(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(0,200,'B');
    map_copy[0] = 'B';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test26(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(0,201,'B');
    map_copy[0] = 'B';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);
    map_copy.erase(200);
    map_copy.erase(201);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test27(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(0,200,'A');
    map_copy[0] = 'A';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);
    map_copy.erase(200);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test28(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(0,202,'A');
    map_copy[0] = 'A';
    map_copy[202]= 'B';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);
    map_copy.erase(200);
    map_copy.erase(201);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test29(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(0,203,'A');
    map_copy[0] = 'A';
    map_copy.erase(20);
    map_copy.erase(40);
    map_copy.erase(50);
    map_copy.erase(60);
    map_copy.erase(70);
    map_copy.erase(100);
    map_copy.erase(200);
    map_copy.erase(201);
    map_copy.erase(203);

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test30(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(0,640,'A');
    map_copy.clear();
    map_copy[0] = 'A';

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test31(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(0,740,'A');
    map_copy.clear();
    map_copy[0] = 'A';

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test32(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(10,700,'B');
    map_copy.clear();
    map_copy[0] = 'A';
    map_copy[10] = 'B';
    map_copy[700] = 'A';

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test33(interval_map<int, char> imap, std::map<int, char> map_copy)
{
    imap.assign(0,700,'B');
    map_copy.clear();
    map_copy[0] = 'B';
    map_copy[700] = 'A';

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
    std::cout << imap << "\n";
}
void test34(interval_map<int, char> _imap, std::map<int, char> _map_copy)
{
    auto imap = interval_map<int, char>{'A'};
    std::map<int, char> map_copy;
    imap.assign(10,100,'A');
    map_copy[0] = 'A';

    std::cout << std::boolalpha << __FUNCTION__ << (map_copy == imap.m_map) << "\n";
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


    _map[400] = 'B';
    _map[500] = 'Z';
    _map[510] = 'B';
    _map[530] = 'C';
    _map[600] = 'D';
    _map[620] = 'B';
    _map[630] = 'C';
    _map[640] = 'A';

    auto map_copy = imap.m_map;

    //std::cout << imap << "\n";
#if 1
    test1(imap, map_copy);
    test2(imap, map_copy);
    test3(imap, map_copy);
    test4(imap, map_copy);
    test5(imap, map_copy);
    test6(imap, map_copy);
    test7(imap, map_copy);
    test8(imap, map_copy);
    test10(imap, map_copy);
    test12(imap, map_copy);
    test13(imap, map_copy);
    test9(imap, map_copy);
    test11(imap, map_copy);

    test14(imap, map_copy);
    test15(imap, map_copy);
    test16(imap, map_copy);
    test17(imap, map_copy);
    test18(imap, map_copy);
    test19(imap, map_copy);
    test20(imap, map_copy);
    test21(imap, map_copy);
    test21(imap, map_copy);
    test22(imap, map_copy);
    test23(imap, map_copy);
    test24(imap, map_copy);
    test25(imap, map_copy);
    test26(imap, map_copy);
    test27(imap, map_copy);
    test28(imap, map_copy);
    test29(imap, map_copy);
    test30(imap, map_copy);
    test31(imap, map_copy);
    test32(imap, map_copy);
    test33(imap, map_copy);
    test34(imap, map_copy);
#else
#endif
}

