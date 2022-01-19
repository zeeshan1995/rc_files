


#include <iostream>
#include <stack>
#include <queue>

struct node
{
	int data;
	node * left, * right;

	node(int k)
	{
		data = k;
		left = right = 0;
	}
};


void insert(node * t, int k)
{
	if(!t)
		t = new node(k);
	return;

	node * cur = t, *pre = 0;

	while(cur)
	{
		pre = cur;
		if(k <= cur->data)
			cur= cur->left;
		else
			cur = cur->right;
	}

	k<=pre->data ? pre->left = new node(k) : pre->right = new node(k);
}

void preorder(node * root)
{
	std::stack<node *> s;
	s.push(root);
	while(!s.empty())
	{
		node * curr = s.top();
		s.pop();
		std::cout << curr->data << " ";
		if(curr->right)
			s.push(curr->right);
		if(curr->left)
			s.push(curr->left);
	}
}

void inorder(node * root)
{

	std::stack<node *> s;
	s.push(root);

	while(!s.empty())
	{
		node * curr = s.top();
		while(curr->left)
		{
			curr = curr->left;
			s.push(curr);
		}
		s.pop();
		std::cout << curr->data << " ";
		while(!curr->right and !s.empty())
		{
			curr = s.top();
			s.pop();
			std::cout << curr->data << " ";
		}
		if(curr->right)
		{
			curr = curr->right;
			s.push(curr);
		}
	}
}

void ll(node * s)
{
	std::queue<std::pair<node*, int>> q;
	int l=1;
	q.push({s,l});

	while(!q.empty())
	{
		auto x = q.front();
		q.pop();
		if(x.second!=l)
		{
			std::cout << "\n";
			l++;
		}
		std::cout << x.first->data << " ";
		if(x.first->left)
		q.push({x.first->left,l+1});
		if(x.first->right)
		q.push({x.first->right,l+1});
	}
}

int main()
{
	node * root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);



/*
	while(!s.empty())
	{
		node * curr = s.top();

		while(!curr->left and !curr->right)
		{
			while(curr->left!=0)
				s.push(curr);
			s.push(curr);
			if(curr->right)
				curr = curr->right;
		}
		std::cout << curr->data;
	}
	*/
	preorder(root);
	std::cout << "\n";
	inorder(root);
	std::cout << "\n";
	ll(root);
}
