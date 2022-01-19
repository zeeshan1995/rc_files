

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

template<typename Tuple, typename Object>
struct join
{
    static auto value = std::tuple_cat(t, std::tuple<Object>{obj});
};

template<typename Tuple, typename Object, typename... Others>
struct join
{
    static auto value = std::tuple_cat(t, join<std::tuple<Object>{obj}, others>{}::value_type...);
};

template<int N, typename Object, typename... Args>
constexpr auto fun(Object && object, Args && ... args)
    ->decltype(join<N-1,std::tuple<Object>{object}, args...>{}::value)
{
    return join<N-1,std::tuple<Object>{object}, args...>{}::value;
}

int main()
{
    int a{};
    std::string s{};
    float f{};
    std::size_t n{};

    std::vector<int>v{};
    std::vector<std::string>vs{};

    //f<2>(a, s, a, v, vs);
    //f<3>(a, s, f, n);
    //fun<3>(a, s, f, n);
    //auto xx = fun<3>(a, s);
    auto xx = fun<3>(a, s, f, s);
    //xx.pp;
}
