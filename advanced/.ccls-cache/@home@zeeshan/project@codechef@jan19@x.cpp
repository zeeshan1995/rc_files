

#include <iostream>
#include <vector>
#include <algorithm>


bool present(int i, int j, int c, std::vector<std::vector<int>> const & v)
{
    if(j-1 >= 0 and i-1 >= 0 and v[i-1][j-1] == c)
        return true;
    if(j-1 >= 0 and i+1 < v.size() and v[i+1][j-1] == c)
        return true;
    if(j+1 < v[i].size() and i+1 < v.size() and v[i+1][j+1] == c)
        return true;
    if(j+1 < v[i].size() and i-1 >=0 and v[i-1][j+1] == c)
        return true;


    if(j-2 >=0 and v[i][j-2] == c)
        return true;
    if(j+2 < v[i].size() and v[i][j+2] == c)
        return true;
    if(i-2 >=0 and v[i-2][j] == c)
        return true;
    if(i+2 < v.size() and v[i+2][j] == c)
        return true;
    return false;
}
int ans = -1;
bool solve(int i, int j, std::vector<std::vector<int>> & v)
{
    int c = 1;
    while(present(i, j, c, v))
        ++c;
    v[i][j] = c;
    ans = std::max(ans, c);
    if(j+1 < v[i].size())
        solve(i, j+1, v);
    else if(i+1 < v.size())
        solve(i+1, 0, v);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int t;
	std::cin >> t;
    while(t--)
    {
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n, std::vector<int>(m,0));
    solve(0,0, v);
    std::cout << ans << "\n";
    for(auto const & x : v)
    {
        for(auto const & y : x)
            std::cout << y << " ";
        std::cout << "\n";
    }
    ans = -1;
    }
}

