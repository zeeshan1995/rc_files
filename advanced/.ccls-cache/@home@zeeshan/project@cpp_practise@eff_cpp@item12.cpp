

#include <iostream>
#include <string>

struct parent
{
    std::string name;
    int age;
};

struct child : public parent
{
    std::string gender;

    child(std::string name,
          int         age,
          std::string gender)
        :parent{std::move(name), age}, gender{std::move(gender)}
        {}

#if 1
    child(child const & rhs)
        : parent{rhs}, gender{rhs.gender}
        {}
#endif
};

int main()
{
    auto parent1 = parent{"parent", 51};
    std::cout << "[" << parent1.name  << "]\n";
    std::cout << "[" << parent1.age   << "]\n";
    std::cout << "-----------------\n";

    auto child1  = child{"parent", 51, "female"};
    std::cout << "[" << child1.name  << "]\n";
    std::cout << "[" << child1.age   << "]\n";
    std::cout << "[" << child1.gender<< "]\n";
    std::cout << "-----------------\n";

    auto child1_copy{child1};
    std::cout << "[" << child1_copy.name  << "]\n";
    std::cout << "[" << child1_copy.age   << "]\n";
    std::cout << "[" << child1_copy.gender<< "]\n";
    std::cout << "-----------------\n";
}
