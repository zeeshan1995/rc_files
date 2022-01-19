#include <algorithm>
#include <iostream>
#include <type_traits>

//handle where function doesn't return anything, such as std::sort
//use enable_if in this case to select overload
//
//
template<typename T>
T square_t(T a) { return a*a; }

template<typename T, typename... Args>
class pipe_t
{
    T _t;
    pipe_t<Args...> _args;

    public:
    pipe_t(T t, Args... args) : _t{t}, _args{args...}{}

    //template <typename U>
    //U operator() (const U & x) const
    //template<typename U>
#if 1
    //template<typename U, typename _ = typename std::enable_if<not std::is_same<decltype(_t(U{})), void>::value>::type>
    template<typename U, typename _ = typename std::enable_if<not std::is_void<decltype(std::declval<U>())>::value>::type>
    auto operator()(const U & x) const
        -> decltype(_args(_t(x)))
    {
        return _args(_t(x));
    }

    template<typename U, typename _ = typename std::enable_if<std::is_void<decltype(_t(U{}))>::value>::type>
    auto operator()(const U & x) const
        -> decltype(_args(x))
    {
        //return _args(_t(x));
        _t(x);
        return _args(x);
    }
#else
    template<typename U>
    auto operator()(const U & x) const
        -> decltype(_args(_t(x)))
    {
        return _args(_t(x));
    }
#endif
};

template <typename T>
class pipe_t<T>
{
    T _t;
    public:
    pipe_t(T t) : _t{t} {}

    //template<typename U>
    //U operator()(const U & x) const
#if 1
    template<typename U, typename _ = typename std::enable_if<not std::is_void<decltype(_t(U{}))>::value>::type>
    auto operator()(const U & x) const
        -> decltype(_t(x))
    {
        return _t(x);
    }

    template<typename U, typename _ = typename std::enable_if<std::is_void<decltype(_t(U{}))>::value>::type>
    auto operator()(const U & x) const
        -> U
    {
        //return _args(_t(x));
        _t(x);
        return x;
    }
#else
    template<typename U>
    auto operator()(const U & x) const
        -> decltype(_t(x))
    {
        return _t(x);
    }
#endif
};

template <typename Argument_Type, typename... Args>
class pipe_wrapper
{
    pipe_t<Args...> _pipe;
    //typename args_type = Argument_Type;
    public:
    //template< typename Argument_Type>
    //pipe_wrapper(Args... args) : _pipe{pipe_t{args...}} {}
    pipe_wrapper(Argument_Type x, Args... args) : _pipe{pipe_t{args...}} {}
};
//template <typename T, typename... Args>
//class pipe_wrapper<T>
//{
//    pipe_t<Args...> _pipe;
//    //typename args_type = Argument_Type;
//    public:
//    pipe_wrapper(Args ...t) : _pipe{pipe_t{t}} {}
//};
//template<typename ...Args>
//pipe_t<Args...> get_pipe(Args... args)
//{
//    return pipe_t<Args...>{args...};
//}

int twice(int a) { return 2*a; }
int square(int a) { return a*a; }
int half(int a) { return a/2; }
std::string asci(int a) {  return "apple";}
//void print(std::string a) { std::cout << "Inside print [ "<< a << "]\n";}
//void print(int a) { std::cout << "Inside print [ "<< a << "]\n";}

int main()
{
    auto print = [](auto const & a){ std::cout << a;};
    //A<std::sort> x;//,char,double> x;
    std::cout << "hello\n";
//    std::cout << get_pipe(twice, square)(5) << "\n";

    //pipe_t pipe1{square_t, twice, half};
    std::cout << pipe_t{square_t<int>, square, asci}(5) << "\n";
    //pipe_t{square_t<int>, square, asci, print}(5);
    pipe_t{print, square_t<int>, square, square_t<decltype(square(2))>, print, twice, print, [](int a) { return a*3;}, print}(4);
    auto const pipe = pipe_wrapper{int{}, square, twice, half, asci, print};
    //pipe(5);
    //auto const pipe = pipe_wrapper<int>{int{}, square, twice, half};
}
