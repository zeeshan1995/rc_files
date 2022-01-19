

#include <iostream>
#include <vector>
#include <algorithm>

const int MAX=1e5+5;

struct tmp
{
	int count,left,right,val;
};
tmp tree[4*MAX];
int A[MAX];
void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int n,k;
	std::string s;
	std::cin >>n >>k >> s;

	std::vector<int>l(n,0),r(n,0);
	for(int i=0,j=n-1,ic=0,jc=0;i<n;i++)
	{
		if(s[i]==1)
			ic++;
		else
			ic=0;
		left[i]=ic;
	}

	build(1,0,s.size()-1);
}
