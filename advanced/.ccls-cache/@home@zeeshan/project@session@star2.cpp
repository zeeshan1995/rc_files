#include <iostream>

int main()

{
    int n;
    std::cout << "how many lines of pattern do you want?" << std::endl;

    std::cin >> n;

    for(int i=1; i<=n; ++i) 

    {
        for(int j=1; j<=n; ++j)
        {

            if(j<=n-i)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << "*";
            }
        }
        std::cout<<std::endl;


    }
}
