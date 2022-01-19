

#include "../toggle_const.hpp"

#include <iostream>

#include <boost/type_index.hpp>

#define PRINT_TYPE(variable) \
    std::cout << "typeof(" << #variable << ") => ["\
              << boost::typeindex::type_id_with_cvr<decltype(variable)>().pretty_name() <<"]\n";

int main()
{
    int non_const_orig = 1;
    auto && const_new = toggle_const::toggle(non_const_orig);
    PRINT_TYPE(const_new);

    int const const_orig = 1;
    auto && non_const_new = toggle_const::toggle(const_orig);
    PRINT_TYPE(non_const_new);
}
