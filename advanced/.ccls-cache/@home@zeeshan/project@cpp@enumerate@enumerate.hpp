
#pragma once

#include <iterator>
#include <utility>


template <typename Iterator
         ,typename index_type = std::size_t>
class loop_element_t
{
    public:
        loop_element_t(Iterator it
                      ,index_type index)
                    : _it{it}
                    , _index{index} {}

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

        bool operator != (loop_element_t & other)
        {
            return _it != other._it;
        }
        auto operator ++()
            -> loop_element_t &
        {
            ++_it;
            ++_index;
            return *this;
        }

        std::pair<int&, index_type> operator*()
        {
            return {*_it, _index};
        }

    private:
        Iterator     _it;
        index_type   _index;
};

template <typename Container
         ,typename index_type = std::size_t>
class enumerate_t : public std::iterator<typename std::iterator_traits<typename Container::iterator>::iterator_category
                                        ,typename std::iterator_traits<typename Container::iterator>::value_type>
{
    private:
        Container  & _container;
        index_type   _index;

    public:
        explicit enumerate_t(Container  & container
                            ,index_type   index = index_type{}) 
                          : _container{container}
                          , _index{index} {}

        auto begin()
            ->decltype(loop_element_t{std::begin(_container), _index})
        {
            return loop_element_t{std::begin(_container), _index};
        }

        auto end()
            ->decltype(loop_element_t{std::end(_container), _index})
        {
            return loop_element_t{std::end(_container)
                                 ,static_cast<index_type>(std::distance(std::end(_container), std::begin(_container)))};
        }
};

template <typename Container
         ,typename index_type = std::size_t>
auto enumerate(Container & container
                        ,index_type index = index_type{})
    ->decltype(enumerate_t{container})
{
    return enumerate_t{container, index};
}
