

#include <iostream>
#include <cstring>


char * reverse(const char * s)
{
	int len = strlen(s);
	char * rev = new char[len+1];
	for(int i=0; i<(len+1)/2; i++)
	{
		rev[i] = s[len-1-i];
		rev[len-1-i] = s[i];
	}
	rev[len]='\0';
	return rev;
}

int main()
{
	char s[100];
	std::cin >> s;
	
	std::cout << reverse(s) << "\n";
}
