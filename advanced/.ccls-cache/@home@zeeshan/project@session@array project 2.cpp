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


    for(int i=0; i<size ;++i)
    {
        if(array[i] == array[size-(i+1)])
            std::cout<< "array no." << i << " " << "and " << "array no." << size-(i+1) << " are same" <<std::endl;
        else
            std::cout<< "array no." << i << " " << "and " << "array no." << size-(i+1) << " are not same " <<std::endl;
    }

    std::cout<<std::endl;

    for(int i=0; i<size ;++i)
    {
        if(i == size-(i+1))
            std::cout << "NOTE: Array no." << i << " " << "does not have a  array to be compared with " << std::endl;
    }
}
