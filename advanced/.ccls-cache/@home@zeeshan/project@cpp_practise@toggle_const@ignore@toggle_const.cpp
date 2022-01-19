#include <iostream>
#include <string>
#include <vector>

# if 1
template<typename T
        ,typename = std::enable_if<std::is_const<T>::value>>
        T _toggle_const(T const & data)
{
        return const_cast<T>(data);
}

template<typename T
        ,typename = std::enable_if<not std::is_const<T>::value>>
        T _toggle_const(T data)
{
        return static_cast<const T>(data);
}

template<typename T>
auto toggle_const(T data)
        -> decltype(_toggle_const(data))
{
        return _toggle_const(data);
}
#else
template<typename T>
const T con(T obj)
{
    return static_cast<const T>(obj);
}

template<typename T>
auto con<const T>(T const obj)
    -> T
{
    return static_cast<T>(obj);
}
#endif

int main()
{
    int a = 24;
    std::cout << typeid(toggle_const(a)).name() << "\n";

    //std::cout << con(a) << "\n";
}

