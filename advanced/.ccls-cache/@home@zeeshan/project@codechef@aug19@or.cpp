#include <iostream>

using namespace std;

template <typename T>
struct order_set {
	struct node {
		int priority;
		size_t subSize;
		T val;
		node * left, * right;
	};
	typedef node * Treap;

	Treap head = NULL;

	inline size_t size() {
		return getSize(head);
	}
	
	inline size_t getSize(Treap t) {
		if (t != NULL) return t -> subSize;
		return 0;
	}

	inline void merge(Treap root) {
		root->subSize = getSize(root->right) + getSize(root->left) + 1;
	}

	inline Treap newNode(T val, int pr) {
		Treap t = (Treap) malloc(sizeof(node));
		t -> val = val;
		t -> priority = pr;
		t -> subSize = 1;
		t -> left = t -> right = NULL;
		return t;
	}

	Treap find(Treap root, T val) {
		if(root == NULL || root -> val == val) return root;
		if(root -> val > val) return find(root -> left, val);
		return find(root -> right, val);
	}

	pair<Treap, Treap> split(Treap root, T val) {
		if (root == NULL) return make_pair((Treap)NULL, (Treap)NULL);
		if (root->val > val) {
			auto p = split(root->left, val);
			root->left = p.second;
			merge(root);
			return make_pair(p.first, root);
		}
		else {
			auto p = split(root->right, val);
			root->right = p.first;
			merge(root);
			return make_pair(root, p.second);
		}
	}

	Treap merge(Treap a, Treap b) {
		if (a == NULL) return b;
		if (b == NULL) return a;
		if (a -> priority > b -> priority) {
			a -> right = merge(a -> right, b);
			merge(a);
			return a;
		}
		else {
			b -> left = merge(a, b->left);
			merge(b);
			return b;
		}
	}

	Treap insert(Treap root, T val, int pr) {
		if (root == NULL) {
			root = newNode(val, pr);
			return root;
		}
		if (root -> priority < pr) {
			Treap newNd = find(root, val);
			if(!newNd) {
				newNd = newNode(val, pr);
				pair<Treap, Treap> p = split(root, val);
				newNd -> left = p.first;
				newNd -> right = p.second;
				merge(newNd);
			}
			return newNd;
		}
		if (root -> val < val) {
			root -> right = insert(root -> right, val, pr);
		}
		else root -> left = insert(root -> left, val, pr);
		merge(root);
		return root;
	}

	Treap remove(Treap root, T val) {
		if (root == NULL) return root;
		if (root -> val == val) return merge(root->left, root->right);
		else if (root -> val > val) root->left = remove(root->left, val);
		else root -> right = remove(root->right, val);
		merge(root);
		return root;
	}

	int countLeq(Treap root, T val) {
		if(!root) return 0;
		if(root->val > val) return countLeq(root->left, val);
		return getSize(root->left) + 1 + countLeq(root->right, val);
	}

	inline void insert(T val) {
		head = insert(head, val, rand());
	}
	inline void erase(T val) {
		head = remove(head, val);
	}
	inline int countLeq(T val) {
		return countLeq(head, val);
	}
};


int main()
{
    int n;

    order_set<int> X;

    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    std::cout << X.countLeq(6) << "\n";
    std::cout << X.size() << "\n";

    order_set<int> Y;
    Y.insert(5);
    Y.insert(10);
    Y.insert(15);
    Y.insert(20);
    std::cout << Y.size() << "\n";

    X.merge(X.head, Y.head);
    std::cout << X.size() << "\n";
    std::cout << Y.countLeq(6) << "\n";
}

