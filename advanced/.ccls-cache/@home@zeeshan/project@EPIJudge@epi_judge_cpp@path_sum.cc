#include <memory>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
bool inorder(const unique_ptr<BinaryTreeNode<int>>& tree, int sum, const int target) {
    if(!tree)
        return false;
    sum+=tree->data;
    if(!tree->left and !tree->right)
        return sum == target;
    return inorder(tree->left, sum, target) || inorder(tree->right, sum, target);
}
bool HasPathSum(const unique_ptr<BinaryTreeNode<int>>& tree,
                int remaining_weight) {
  // TODO - you fill in here.
    return inorder(tree, 0, remaining_weight);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "remaining_weight"};
  return GenericTestMain(args, "path_sum.cc", "path_sum.tsv", &HasPathSum,
                         DefaultComparator{}, param_names);
}
