

#include <vector>
#include <iostream>

//& --> reference  just like pointer

//pass by refernence 
//pass by copy


//void display(std::vector<int> const & v); --> function declaration
void display(std::vector<int> const & v) //--> function defination
{
    //v[0] = 100;
    for(int i=0; i<v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << __FUNCTION__ << "\n";
}

int main()
{
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    display(nums);
}

