

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <numeric>

void check_n_insert(int n,  std::vector<int> & visited, std::set<int> & result)
{ 
   if(!visited[n])
       result.insert(n);
   ++visited[n];
}

int solve(int i, int j, std::vector<std::vector<int>> & dp, std::vector<int> const & nums, std::vector<int> & visited, std::set<int> & result)
{
    if(i == j)
    {
        dp[i][j] = nums[i];
        check_n_insert(dp[i][j], visited, result);
        return nums[i];
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    /*
    if( j > i)
    {
        int iplus_jminus = solve(i+1, j-1, dp, nums, visited, result);

        dp[i][j-1] = nums[i] | iplus_jminus;
        dp[i][j] = dp[i][j-1] | nums[j];

        dp[i+1][j-1] = iplus_jminus;
        dp[i+1][j] = dp[i+1][j-1] | nums[j];

        check_n_insert(dp[i][j-1], visited, result);
        check_n_insert(dp[i][j], visited, result);

        check_n_insert(dp[i+1][j-1], visited, result);
        check_n_insert(dp[i+1][j], visited, result);
    }
    */
    if(j > i)
    {
        int i_1_j = solve(i+1, j, dp, nums, visited, result);
        int i_j_1 = solve(i, j-1, dp, nums, visited, result);
        dp[i][j] = i_1_j | nums[i];
    }

    return dp[i][j];
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;

    while(t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> nums(n);
        std::iota(nums.begin(), nums.end(), 1);

        //for(auto & x : nums)
        //    std::cin >> x;

        std::vector<int>visited(1e9+5, 0);
        std::set<int>result;
        std::vector<std::vector<int>>dp(n, std::vector<int>(n,-1));

        solve(0, n-1, dp, nums, visited, result);

        for(auto x : dp)
        {
            for(auto y : x)
                std::cout << y << " ";
            std::cout <<"\n";
        }

        std::cout << result.size() << "\n";
        
        int q;
        std::cin >> q;

        while(q--)
        {

        }
    }
}
