// A C++ program to demonstrate use of constexpr
#include<iostream>
#include <vector>
using namespace std;
 
constexpr long long int fib(int n)
{
	//std::cout << n << " ";
   // return (n <= 1)? n : fib(n-1) + fib(n-2);
   fib(n+1);
   return 0;
}

constexpr long long solve(long long n)
{
	//::vector<int>nums(n);
	//nums.push_back(0);
	//nums.push_back(1);
	long long j=1;
	for(int i=2;i<n;i++)
		j*=i;
		//nums[i] = nums[i-1] + nums[i-2];
	//return nums;
	return j;
}
 
int main ()
{
    // value of res is computed at compile time. 
	const int x=70;
    std::cout << "Started calculation\n";
    constexpr long long res = fib(70);
    cout << res << "\n";
	//constexpr long long y = solve(x);
    return 0;
}
