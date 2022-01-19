#include <iostream>

int main()

{

int sum = 0;
    int a;
    
    std::cout << "Enter your Number:";
    std::cin >> a;
    
    std::cout << std::endl;

    for(int i = 1; i < 11 ; ++i)
      
    { std::cout << i*a<<std::endl;
  
    sum = sum+(i*a);}
   
    std::cout << std::endl;
    
    std::cout << "The total Sum of the Numbers are:" << sum<<" " << std::endl;
    
    
     //std::cout<<sum<<std::endl;//
    
    
    
    }









