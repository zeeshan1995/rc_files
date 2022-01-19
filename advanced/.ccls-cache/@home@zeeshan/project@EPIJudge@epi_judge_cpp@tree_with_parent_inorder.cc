#include <vector>

#include "binary_tree_with_parent_prototype.h"
#include "test_framework/generic_test.h"
using std::vector;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  std::vector<int>nums;
  auto node = tree.get();
  auto left_visited = false;
  while(node)
  {
      if(!left_visited)
      {
          while(node->left)
              node = node->left.get();
      }
      nums.push_back(node->data);
      left_visited = true;
      if(node->right)
      {
          node = node->right.get();
          left_visited = false;
      }
      else if(node->parent)
      {
          while(node->parent and node == node->parent->right.get())
              node = node->parent;
          node = node->parent;
      }
      else
          break;
  }
  return nums;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_with_parent_inorder.cc",
                         "tree_with_parent_inorder.tsv", &InorderTraversal,
                         DefaultComparator{}, param_names);
}
