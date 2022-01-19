#include<bits/stdc++.h>

using namespace std;



int impl(long long N, std::unordered_map<long long, int> & dp)
{
    if(dp.find(N) != dp.end())
        return dp[N];

   auto power = int(std::log10(N));

   long long divisor = 1;

   while(power--)
   {
       divisor*=10;
       divisor+=1;
   }

   long long remaining = N;
   long long ans = 0;
   if(divisor>1)
   {
       int next_div = divisor*10+1;
       int next_ans = next_div - remaining < remaining ? impl(next_div - remaining, dp) + std::to_string(next_div).size(): -1;
       int cur_ans = std::to_string(divisor).size() * int(remaining/divisor) + impl(remaining%divisor, dp);
       if(next_ans!=-1)
        ans = std::min(next_ans, cur_ans);
   }
   else
    ans += std::min(remaining, std::abs(13-remaining));

   std::cout << N << " " << ans << "\n";
   return ans; 

}



int solve (long long N) {

   std::unordered_map<long long, int>dp;

   return impl(N,dp);

}



int main() {



    ios::sync_with_stdio(0);

    cin.tie(0);

    int T;

    cin >> T;

    for(int t_i = 0; t_i < T; t_i++)

    {

        long long N;

        cin >> N;



        int out_;

        out_ = solve(N);

        cout << out_;

        cout << "\n";

    }

}
