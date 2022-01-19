

#include <iostream>
#include <stack>

void bott(std::stack<int> & s, int x)
{
	if(s.empty())
	{
		s.push(x);
		return ;
	}
	int k = s.top();
	s.pop();
	bott(s,x);
	s.push(k);
}
void rev(std::stack<int> & s)
{
	if(!s.empty())
		return;
	int x = s.top();
	s.pop();
	rev(s);
	bott(s,x);
}
int main()
{
	std::stack<int>s;
	for(int i=0; i<10; i++)s.push(i);

	rev(s);

	while(!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
}
