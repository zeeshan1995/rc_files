

#include <iostream>

int main()
{
    int size;
    std::cin >> size;

    //int* n = new int;
    int* array = new int[size];


    //std::cin >> *n;
    //std::cout << "n => " << (long long)n << std::endl;



    for(int i=0; i<size; ++i)
    {
        std::cin >> array[i];
    }

    std::cout << "Printing\n";


    for(int i=0; i<size; ++i)
    {
        std::cout << array[i] << " ";
    }

    //delete n;
    delete []array;
}
