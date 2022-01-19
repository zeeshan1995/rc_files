#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

int dept(const BinaryTreeNode<int>*node)
{
    int d = 0;
    while(node->parent)
    {
        ++d;
        node=node->parent;
    }
    return d;
}
BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  // TODO - you fill in here.
  auto r_n0 = node0.get(), r_n1 = node1.get();
  auto d0 = dept(r_n0);
  auto d1 = dept(r_n1);

  if(d1 > d0)
      std::swap(r_n0, r_n1);

  auto diff = std::abs(d0-d1);

  while(diff--)
      r_n0 = r_n0->parent;

  while(r_n0 != r_n1)
  {
      r_n0 = r_n0->parent;
      r_n1 = r_n1->parent;
  }
  return r_n0;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_with_parent.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
