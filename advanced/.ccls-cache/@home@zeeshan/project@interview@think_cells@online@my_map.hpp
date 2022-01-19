#include <map>
#include <limits>

template<typename K, typename V>
class interval_map {
	std::map<K,V> m_map;
public:

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
    /*
    friend std::ostream & operator <<(std::ostream & out, interval_map const & imap)
    {
        out << "------------------\n";
        for(auto const & p : imap.m_map)
            out << p.first << " " << p.second << "\n";
        out << "------------------\n";
        return out;
    }
    */
};
