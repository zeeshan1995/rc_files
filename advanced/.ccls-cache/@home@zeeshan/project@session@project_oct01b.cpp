#include <iostream>

int main()
{
      int size;
    
      std::cout << "How many numbers you want to enter?: ";
      std::cin >> size;
    
      int *array = new int[size];
      std::cout << "Enter your numnbers" << std::endl;
    
    for(int i=0; i<size ;++i)
    {
        std::cin >> array[i];
    } 

/*
 * boolean --> True, False
 *
 * */
    bool same = true;
    for(int i=0; i<size ;++i)
    {
        if(array[i] != array[size-(i+1)])
        {
            same = false;
            break;
        }
    }
    if( same == false)
        std::cout << "NO same" << std::endl;
    else
        std::cout << "Same" << std::endl;
}
