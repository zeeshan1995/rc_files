#include <iostream>

int main()

{
    int input;
    
    std::cout << "Enter the number of elements you want in the series:";
    std::cin >> input;
    
    int *array = new int[input];
    
    std::cout << "Enter the first two desired elemnts of the series:" << std::endl;
    
    std::cin >> array[0] >> array[1];
    int a = array[0];
    int b = array[1];
    
    for(int i=2; i<input ;++i)
    {
        array[i] = array[i-1] + array[i-2];
    }
    std::cout << "series in reverse order:";
    
    for(int i=input-1; i>=0; --i)
   {
       std::cout << array [i] << ",";
   }
}
