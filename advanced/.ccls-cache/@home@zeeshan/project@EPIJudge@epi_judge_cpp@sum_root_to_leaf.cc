#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

void preorder(const unique_ptr<BinaryTreeNode<int>>& tree, int n, int & sum) {
    if(!tree)
        return;
    n<<=1;n+=tree->data;
    if(!tree->left and !tree->right)
    {
        sum+=n;
        return;
    }
    preorder(tree->left, n, sum);
    preorder(tree->right, n, sum); 
}

int SumRootToLeaf(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  int sum = 0;
  preorder(tree, 0, sum);
  return sum;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "sum_root_to_leaf.cc", "sum_root_to_leaf.tsv",
                         &SumRootToLeaf, DefaultComparator{}, param_names);
}
