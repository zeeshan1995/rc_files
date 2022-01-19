

#include <bits/stdc++.h>
#include <unistd.h>
int main()
{
    std::ofstream out;
    out.open("apple", std::ofstream::out);
    if( ! out.is_open())
        throw "Exception";
    if(access("ball", W_OK) == -1)
        throw std::runtime_error{"Failure"};
}
