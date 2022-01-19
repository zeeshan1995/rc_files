#include <iostream>
#include <vector>


//PUSH BACK
/*
int main()
{
    std::vector<int> vec1;
    int n;

    std::cout<<"Enter numvberf of elements you want to enter ";
    std::cin>> n;

    for (int i=0; i<n; i++)
    {
        int element;
        std::cout<<"Enter elements to add to the vector: ";
        std::cin>>element;

        vec1.push_back(element);
    }


    for (int i=0; i<vec1.size(); i++)
        std::cout<<vec1[i] << " ";
    std::cout << std::endl;

    return 0;
}
*/

//POP BACK
/*
int main()
{
    std::vector<int> vec1;
    int element,size;

    std::cout<<"Enter numvberf of elements you want to enter ";
    std::cin>> size;

    for (int i=0; i<size; i++)
    {
        std::cout<<"Enter elements to add to the vector: ";
        std::cin>>element;

        vec1.push_back(element);
    }
    vec1.pop_back();
    for (int i=0; i<vec1.size(); i++)
    {
        std::cout<<vec1[i] << " " << std::endl;
    }

    return 0;
}
*/

//DISPLAY FUNCTION
/*
void display(std::vector<int> &v)
{
 for (int i=0; i<v.size(); i++)
 {
   std::cout<<v[i] << " " << std::endl;
  }
}

int main()
{
    std::vector<int> vec1;
    int element,size;

    std::cout<<"Enter numvberf of elements you want to enter ";
    std::cin>> size;

    for (int i=0; i<size; i++)
    {
        std::cout<<"Enter elements to add to the vector: ";
        std::cin>>element;

        vec1.push_back(element);
    }
    display(vec1);

    return 0;
}
*/

//INSERT ELEMENT USING ITERATION

int main()
{
    std::vector<int> vec1;
    int element,size;

    std::cout<<"Enter numvberf of elements you want to enter ";
    std::cin>> size;

    for (int i=0; i<size; i++)
    {
        std::cout<<"Enter elements to add to the vector: ";
        std::cin>>element;

        vec1.push_back(element);
    }
//method-1
/*
    std::vector<int> :: iterator iter = vec1.begin();
    vec1.insert(iter,10);
*/

//method-2
/*
    std::vector<int> :: iterator iter =vec1.begin();
    vec1.insert(iter+2,10);
*/

//method-3
/*
    std::vector<int> :: iterator iter = vec1.end();
    vec1.insert(iter,10);
*/
  
    //method-4

    std::vector<int> :: iterator iter =vec1.end();
    vec1.insert(iter-1,10);



    for (int i=0; i<vec1.size(); i++)
    {
        std::cout<<vec1[i] << " " << std::endl;
    }

    return 0;

}
