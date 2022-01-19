
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

#if 0
template <typename Container_t, typename Callable_t>
void pipe(Container_t & container, Callable_t callable)
{
    callable(std::begin(container), std::end(container));
}

template <typename Container_t, typename Callable_t, typename... Callables_t>
void pipe(Container_t & container, Callable_t callable, Callables_t... callables)
{
    callable(std::begin(container), std::end(container));
    pipe(container, callables...);
}
#endif
//template<typename Iterator>
//auto const sort = [](Iterator begin, Iterator end){std::sort(begin, end);};

int main()
{
    auto nums = std::vector<int>{1,2,4,5,1,7,-1,-5,-3,10};
    pipe(nums, std::sort<std::vector<int>::iterator>, std::unique<std::vector<int>::iterator>);
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}
