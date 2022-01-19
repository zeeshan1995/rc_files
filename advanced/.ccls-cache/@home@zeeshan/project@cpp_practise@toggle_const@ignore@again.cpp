

#include <iostream>

#include <boost/type_index.hpp>

#define PRINT_TYPE(variable) \
    std::cout << #variable << " "\
              << boost::typeindex::type_id_with_cvr<decltype(variable)>().pretty_name() <<"\n";

template<typename T>
struct toggle_const
{
    using type = const T;
};

template<typename T>
struct toggle_const<const T>
{
    using type = T;
};

template<typename T>
constexpr auto toggle(T && object)
    -> typename toggle_const<typename std::remove_reference<T>::type>::type &
{
    return const_cast<typename toggle_const< typename std::remove_reference<T>::type >::type &>(object);
}

int main()
{
    int non_const_orig = 1;
    auto && const_new = toggle(non_const_orig);
    PRINT_TYPE(const_new);

    int const const_orig = 1;
    auto && non_const_new = toggle(const_orig);
    PRINT_TYPE(non_const_new);
}

