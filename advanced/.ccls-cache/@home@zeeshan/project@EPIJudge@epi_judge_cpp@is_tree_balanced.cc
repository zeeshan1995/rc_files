#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
std::pair<bool, int> IsBalanced_impl(const unique_ptr<BinaryTreeNode<int>>& tree) {
    if(!tree)
        return {true, 0};
    auto left = IsBalanced_impl(tree->left);
    auto right = IsBalanced_impl(tree->right);
    if(!left.first or !right.first or std::abs(left.second - right.second)>1)
        return {false, 0};
    return {true, std::max(left.second, right.second) + 1};
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  auto [balanced, height] = IsBalanced_impl(tree);
  return balanced;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
