

#include <iostream>

#include <boost/type_index.hpp>

#define PRINT_TYPE(variable) \
    std::cout << #variable << " "\
              << boost::typeindex::type_id_with_cvr<decltype(variable)>().pretty_name() <<"\n";

#if 0
template<typename T, T val>
struct toggle_const
{
    using value_type = const T;//static_cast<const T>(val);
    const T value = static_cast<const T>(val);
};

template<typename T, T val>
struct toggle_const
{
    using value_type = T;//static_cast<const T>(val);
    T value = const_cast<T>(val);
};

template<typename T>
auto toggle(T object)
    -> decltype(toggle_const<T, 23>{}.value)
{
    return toggle_const <int, 23>{}.value;
}
#endif

template<typename T>
struct toggle_const
{
    using value_type = const T;
};

template<typename T>
struct toggle_const<const T>
{
    using value_type = T;
};

template<typename T>
auto toggle(T && object)
    -> typename toggle_const<T>::value_type
{
    //typename toggle_const<T>::value_type.x;//{"gfgf"};
    return const_cast<typename toggle_const<T>::value_type>(object);
}

int main()
{
    //auto xx = toggle_const<int, 23>{};
    //PRINT_TYPE(xx.value);

    const int const_int = 1;
    auto && non_const_int = toggle(const_int);
    PRINT_TYPE(non_const_int);

    auto && should_be_const = toggle(non_const_int);
    PRINT_TYPE(should_be_const);
}
