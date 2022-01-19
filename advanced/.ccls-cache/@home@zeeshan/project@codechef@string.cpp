

#include <iostream>
#include <vector>
#include <string>

std::vector<std::pair<int,int>>start,end;


void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = 0;
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
		if(s[start]==s[end])
			tree[node]=0;
        tree[node] = tree[2*node] + tree[2*node+1];
		
    }
}


int main()
{
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	while(n--)
	{
		std::string s;
		std::cin >> s;

		char x = s[0];
		int xc = 1, yc = 0;


		start.push_back({xc,yc});

		for(int i=1;i<s.size();i++)
		
			if(s[i]==x)
				xc++;
			else
				yc++;
			start.push_back({xc,yc});
		}
	}
}
