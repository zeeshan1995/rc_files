

3 6 9 13 15 19 23
n = 15
k = 2


int k_nearest(std::vector<int> const & nums, int n, int k)
{
    auto it = std::lower_bound(nums.begin(), nums.end(), n); //it == 15;
    auto left = it, right = it;
    int diff = 0;
    auto ans = it;
    while(k)
    {
        if(left != nums.begin() and right != nums.end())
        {
            auto left_diff = std::abs(*it - *(left-1));
            auto right_diff = std::abs(*it - *(right+1));
            if(left_diff < right_diff)
            {
                --left;
                ans = left;
            }
            else
            {
                ++right;
                ans = right;
            }
            --k;
        }
        else if(left != nums.begin())
        {
            left-=k;
            ans = left;
            k=0;
        }
        else
        {
            right+=k;
            ans = right;
            k=0;
        }

    }
    return *ans;
}

