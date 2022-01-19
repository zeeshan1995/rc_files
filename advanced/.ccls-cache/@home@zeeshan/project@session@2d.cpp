

#include <iostream>

int main()
{
    int ** arr = new int* [3];
    for(int i=0; i<3; ++i)
    {
        arr[i] = new int[10];
    }

    /*
     * arr[0] = new int[2];
     * arr[1] = new int[2];
     * arr[2] = new int[2];
     */

    for(int i = 0; i<3; ++i)
    {
        for(int j=0; j<10; ++j)
        {
            std::cin >> arr[i][j];
        }
    }



    /*
     * i => 0 arr[0][0]
     *      1 arr[1][1]
     *      2 arr[2][2]
     */
}
