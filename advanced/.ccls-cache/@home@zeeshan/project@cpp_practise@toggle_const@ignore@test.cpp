

#include <iostream>

#include <boost/type_index.hpp>

#define PRINT_TYPE(variable) \
    std::cout << #variable << " "\
              << boost::typeindex::type_id_with_cvr<decltype(variable)>().pretty_name() <<"\n";

int main()
{
    int a = 23;
    int & x = a;
    auto && non_const = const_cast<int &>(x);
    auto && _const = const_cast<const int &>(x);
    PRINT_TYPE(non_const);
    PRINT_TYPE(_const);
}
