#include <string>
#include <istream>

class Person
{
    public:
        Person(std::string name, int age) : _name{name}, _age{age} {}

        Person(const Person & other) : _name{other._name}, _age{other._age} {}

        Person(Person && other) : _name{std::move(other._name)}, _age{other._age} { }

        ~Person() {}

    private:
        std::string _name;
        int _age;
};

std::string name = "zeeshan";

std::cout << name << "\n"; // zeeshan


std::string name2{std::move(name)};


std::cout << name2 << "\n"; //zeeshan

std::cout << name << "\n"; //

std::vector<int> nums = {5, 9, 7,  0, 8, 0, 1, 0};

std::vector<int> nums put_zero_at_end(std::vector<int> const & nums)
{
    std::vector<int>res(nums.size());

    int front = 0, back = nums.size()-1;
    for(auto x : nums)
    {
        if(x)
        {
            nums.insert(x, front);
            ++front;
        }
        else
        {
            nums.insert(x, back);
            --back;
        }
    }
    return res;
}

void nums put_zero_at_end(std::vector<int> & nums)
{
    int  non_zero_pos = 0;
    for(int i=0; i<nums.size(); ++i)
    {
        if(nums[i])
            nums[non_zero_pos++] = nums[i];
    }

    for(int i=non_zero_pos; zero>=0; --zero)
        nums[i] = 0;
}

int * n = new int{23};
