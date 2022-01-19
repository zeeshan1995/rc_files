#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"

BinaryTreeNode<int>* FindSuccessor(
    const unique_ptr<BinaryTreeNode<int>>& node) {
  // TODO - you fill in here.
  if(!node)
      return nullptr;
  auto tree = node.get();
  if(tree->right)
  {
      //go the left most of the subtree;
      tree = tree->right.get();
      while(tree->left)
          tree = tree->left.get();
      return tree;
  }
  if(!tree->right and tree->parent and tree == tree->parent->left.get())
      return tree->parent;
  if(!tree->right and tree->parent and tree == tree->parent->right.get())
  {
      //move up till parent is left node;
      tree = tree->parent;
      while(tree->parent and tree == tree->parent->right.get())
          tree = tree->parent;
      return tree->parent;
  }
  return nullptr;
}
int FindSuccessorWrapper(const unique_ptr<BinaryTreeNode<int>>& tree,
                         int node_idx) {
  auto result = FindSuccessor(MustFindNode(tree, node_idx));
  return result ? result->data : -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree", "node_idx"};
  return GenericTestMain(args, "successor_in_tree.cc", "successor_in_tree.tsv",
                         &FindSuccessorWrapper, DefaultComparator{},
                         param_names);
}
