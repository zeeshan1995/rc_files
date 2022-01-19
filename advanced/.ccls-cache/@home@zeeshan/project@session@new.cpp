#include <iostream>

int main()

{
    
   int a,b;
   
   std::cin >> a >> b;
    
  
    
   for(int i = a; i<=b; ++i)
    
   {  if(i<=9)
      {if (i == 1 )
        std::cout << "one" << std::endl; 
    
      if(i == 2)
        std::cout << "two" << std::endl;
        
      if(i == 3)
        std::cout << "three" << std::endl;
        
      if(i == 4)
        std::cout << "four" << std::endl;
        
      if(i == 5)
        std::cout << "five" << std::endl;
        
      if(i == 6)
        std::cout << "six" << std::endl;
        
      if(i == 7)
        std::cout << "seven" << std::endl;
        
      if(i == 8)
        std::cout << "eight" << std::endl;
        
      if(i == 9)
        std::cout << "nine" << std::endl;}
        
      if(i > 9)
    {
      if(i % 2 == 0)
        std::cout << "even" << std::endl;
        else std::cout << "odd" << std::endl;}}
        
    
    
 
    }