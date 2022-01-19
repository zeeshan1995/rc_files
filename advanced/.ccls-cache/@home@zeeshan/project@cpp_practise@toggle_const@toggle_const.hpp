#pragma once

#include <type_traits>

namespace toggle_const{

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
}
