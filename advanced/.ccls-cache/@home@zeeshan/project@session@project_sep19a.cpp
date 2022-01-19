#include <iostream>

int main()

{
    
   int a;
   int b;
   
   std::cin >> a >> b;

   int z;

   std::cout<<std::endl; 

   for(int i = a; i<=b; ++i)
   { 

       std::cout << "Starting loop => " << i << std::endl;
       if(++i<=9)
       {
           std::cout << "Before 1 => " << i << std::endl;
           if (++i == 1 )
               std::cout << "one" << std::endl; 

           std::cout << "Before 2 => " << i << std::endl;
           if(++i == 2)
               std::cout << "two" << std::endl;
           std::cout << i << std::endl;

           std::cout << "Before 3 => " << i << std::endl;
           if(++i == 3)
               std::cout << "three" << std::endl;

           std::cout << "Before 4 => " << i << std::endl;
           if(++i == 4)
               std::cout << "four" << std::endl;

           std::cout << "Before 5 => " << i << std::endl;
           if(++i == 5)
               std::cout << "five" << std::endl;

           std::cout << "Before 6 => " << i << std::endl;
           if(++i == 6)
               std::cout << "six" << std::endl;

           std::cout << "Before 7 => " << i << std::endl;
           if(++i == 7)
               std::cout << "seven" << std::endl;

           std::cout << "Before 8 => " << i << std::endl;
           if(++i == 8)
               std::cout << "eight" << std::endl;

           std::cout << "Before 9 => " << i << std::endl;
           if(++i == 9)
               std::cout << "nine" << std::endl;
       }
       else if(++i > 9)
       {
           std::cout << i << std::endl;
           if( ++i % 2 == 0)
               std::cout << "even" << std::endl;
           else std::cout << "odd" << std::endl;
       }
   }
   std::cout<<std::endl;
}
