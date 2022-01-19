

#include <iostream>
#include <vector>


double solve(std::vector<int> const & a, std::vector<int> const & b)
{
    int size = a.size() + b.size();
    int l = size/2;

    int i=0; j=0;
    int a,b;
    while(i + j < size)
    {
        if(a[i] < a[j])
        {
            ++i;
        }
        else
            ++j;
    }
    if( size & 1)
        return std::max(a[i], a[j]);
    else
    {
        return std::max(a[i]

    }
}
