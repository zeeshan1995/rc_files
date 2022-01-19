#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

bool compare(const std::unique_ptr<BinaryTreeNode<int>> & tree, const std::unique_ptr<BinaryTreeNode<int>> &other) 
{
    if(!tree and !other)
        return true;

    if(!(tree and other))
        return false;

    return tree->data==other->data and compare(tree->left, other->right) and compare(tree->right, other->left);
}
bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  if(!tree)
      return true;
  return compare(tree->left, tree->right);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_symmetric.cc", "is_tree_symmetric.tsv",
                         &IsSymmetric, DefaultComparator{}, param_names);
}
