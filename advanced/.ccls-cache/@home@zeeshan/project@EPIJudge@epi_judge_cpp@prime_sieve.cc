#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
  // TODO - you fill in here.
    std::vector<bool>is_prime(n+5,true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<=sqrt(n); ++i)
    {
        if(!is_prime[i])
            continue;
        for(int j=2*i; j<=n; j+=i)
            is_prime[j] = false;
    }
    std::vector<int>primes;
    for(int i=2; i<=n; ++i)
    {
        if(is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}
