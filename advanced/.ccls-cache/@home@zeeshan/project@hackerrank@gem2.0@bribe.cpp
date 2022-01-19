

#include <iostream>
#include <vector>

void print(std::vector<int> x)
{
    for(int i=0; i<x.size(); ++i)
        std::cout << "[" << i << "=>" << x[i] << "]\n";
    //std::cout << "\n";
}

void printi(std::vector<int> x)
{
    for(int i=1; i<x.size(); ++i)
        std::cout << "[" << i << "=>" << x[i] << "]\n";
    //std::cout << "\n";
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    std::cin >> n;
    
    std::vector<int> nums(n);
    for(auto & x : nums)
        std::cin >> x;

    std::vector<int>count(nums.size()+1, 0);
    std::vector<int>index(nums.size() + 1);
    for(int i = 0; i<nums.size(); ++i)
        index[nums[i]] = i;

    //print(index);
    bool error = false;
    int ans = 0;
    for(int i=1; i<=nums.size() and not error; ++i)
    {
        std::cout << i <<  " " << index[i] << ":\n";
        print(nums);
        std::cout << "____\n";
        printi(index);
        if(index[i] == i-1)
            continue;
        else if (index[i] >= i and index[i] < i+2)
        {
            std::cout << "greater\n";
            auto index_of_i = index[i];
            auto pre = nums[index_of_i -1];
            //if(count[i] >= 2 or count[pre] >= 2)
            if(count[pre] >= 2)
                error = true;
            //count[i]++;
            count[pre]++;
            std::cout <<index_of_i << " " << pre << "index\n";
            std::cout << nums[index_of_i] << " " << nums[index_of_i-1] << "nums\n";
            std::swap(nums[index_of_i], nums[index_of_i - 1]);
            index[i] = index_of_i - 1;
            index[pre] = index_of_i;
            ++ans;
            --i;
        }
        else if(index[i] < i and index[i] > i-2)
        {
            std::cout << "less";
            auto index_of_i = index[i];
            auto pos = nums[index_of_i + 1];
            if(count[i] >= 2)// or count[pos] >= 2)
                error = true;
            count[i]++;
            //count[pos]++;
            std::swap(nums[index_of_i], nums[index_of_i + 1]);
            index[i] = index_of_i + 1;
            index[pos] = index_of_i;
            ++ans;
            --i;
        }
        //else
        //{
        //    error = true;
        //    break;
        //}
    }
    print(count);
    if(error)
        std::cout << "Too chaotic\n";
    else
        std::cout << ans << "\n";
}
