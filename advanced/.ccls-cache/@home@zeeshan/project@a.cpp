#include<bits/stdc++.h>

using namespace std;



int solve (long long N) {

   // Write your code here

   auto power = int(std::log10(N));
   std::cout <<power << " ";

   auto divisor = 1;

   while(power--)

   {

       divisor*=10;

       divisor+=1;

   }
   std::cout << divisor << "\n";

   long long remaining = N;

   int ans = 0;

   while(divisor>1)
   {
       std::cout << divisor << " " << std::to_string(divisor) << " " <<std::to_string(divisor).size() << "\n";

       ans+=std::to_string(divisor).size() * int(remaining/divisor);

       remaining%=divisor;

       divisor/=10;
   }
   std::cout << "-------\n";
   std::cout << ans <<" " << remaining <<"\n";

   if(remaining > 5)

    ans += (13-remaining);

   else

    ans+=remaining;

   return ans;

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
