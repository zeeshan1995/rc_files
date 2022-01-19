
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    freopen("input.txt", "r", stdin);

    int n;
    std::cin >> n;

    std::vector<unsigned long long> nums(n);
    for(auto & x : nums)
        std::cin >> x;
    std::cout << nums[n-1] << "\n";

    std::vector<unsigned long long> start(n), end(n);

    start[0] = nums[0];
    std::cout << start[0] << "\n";
    for(int i=1; i<n; ++i)
    {
        start[i] = start[i-1]*nums[i];
        if(start[i] > start[i-1] )
        {
            std::cout << i << "\n";
            break;
        }
    }
    end[n-1] = nums[n-1];
    for(int i= n-2; i>=0; --i)
        end[i] = end[i+1]*nums[i];
    std::cout << start[n-1] << "\n";
}
