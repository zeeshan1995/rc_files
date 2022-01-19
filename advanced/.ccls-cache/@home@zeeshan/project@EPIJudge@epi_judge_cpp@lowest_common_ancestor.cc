#include <memory>

#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
#include <utility>
using std::unique_ptr;

std::pair<bool, BinaryTreeNode<int>*> found(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {

    if(!tree)
        return {false, nullptr};

    if(tree==node1 and tree==node0)
        return {true, tree.get()};
    
    auto left = found(tree->left, node0, node1);
    auto right = found(tree->right, node0, node1);

    if(right.second or left.second)
        return right.second ? right : left; 
    if(left.first and right.first)
        return {true, tree.get()};
    if((right.first or left.first) and (tree==node0 or tree==node1))
        return {true, tree.get()};
    if(right.first or left.first)
        return {true, nullptr};

    if(tree==node0 or tree==node1)
        return {true, nullptr};

    return {false,nullptr};
}
BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  if(!tree)
      return nullptr;
  return found(tree, node0, node1).second;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(tree, node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
