

#include <iterator>
#include <vector>
#include <iostream>


template <typename Iterator
         ,typename index_type = std::size_t>
class loop_element_t
{
    public:
        auto value()
            -> typename Iterator::value_type
        {
            return *_it;
        }

        auto index()
            -> index_type
        {
            return _index;
        }

        operator !=(loop_element_t other 

    private:
        Iterator     _it;
        index_type   _index;
};

template <typename Container
         ,typename index_type = std::size_t>
loop_element_t enumerate(Container & container
                        ,index_type index = index_type{})
{
    return loop_element_t<Container::iterator, index_type>{std::begin(container), std::end(container), index};
}

template <typename Container
         ,typename index_type = std::size_t>
class enumerate_t : public std::iterator<typename std::iterator_traits<typename Container::iterator>::iterator_category
                                        ,typename std::iterator_traits<typename Container::iterator>::value_type>
{
    protected:
        Container & _container;

    public:
        explicit enumerate_t(Container & container) : _container{container} {}

        loop_element_t & operator*()
        {
            return loop_element_t{_it, _index()};
        }

        enumerate_t begin()
        {
            return loop_element_t{_it, _index()};
        }

        enumerate_t end()
        {
            return loop_element_t{std::end(_container), _index()};
            //return *this;//std::end(_container);
        }

        bool operator !=(enumerate_t & other)
        {
            return ot_it != std::end(_container);
        }
        void operator++()
        {
            ++_it;
            ++_index_v;
        }

    private:
        typename Container::value_type & _value()
        {
            auto & temp = *_it;
            ++_it;
            return temp;
        }

        index_type _index()
        {
            auto & tmp = _index_v;
            ++_index_v;
            return tmp;
        }

    private:
            typename Container::iterator _it = _container.begin();
            auto _index_v = index_type{};
};


int main()
{
    std::vector<int> nums{1,2,3,4,5,6};
    for(auto x : enumerate_t{nums})
        std::cout << x << "\n";
    //auto it = enumerate_t{nums};
    //std::cout << it.begin() << "\n";
    //it.end();
    //*it = 23;
    //std::cout <<nums[1] << "\n";
    //std::cout <<*it << "\n";
    //std::cout <<*it << "\n";
    //std::cout <<*it << "\n";
    //std::cout <<*it << "\n";
    //std::cout <<*it << "\n";
    //std::cout <<*it << "\n";
    //std::cout <<*it << "\n";
}
