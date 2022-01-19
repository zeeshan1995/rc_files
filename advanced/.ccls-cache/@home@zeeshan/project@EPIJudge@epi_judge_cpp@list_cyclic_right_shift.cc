#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

shared_ptr<ListNode<int>> CyclicallyRightShiftList(shared_ptr<ListNode<int>> L,
                                                   int k) {
  // TODO - you fill in here.
  auto k_forward = L, cur= L;
  if(not L or not k)
      return L;
  auto len = 0;
  while(--k and k_forward)
  {
      k_forward = k_forward->next;
      ++len;
  }

  if(not k_forward)
  {
      k = (len+k+1)%len;
      if(not k)
          return L;
      k_forward = L;
      while(--k and k_forward)
          k_forward = k_forward->next;
  }

  if(k_forward)
  {
      k_forward = k_forward->next;
      while(k_forward and k_forward->next)
      {
          k_forward = k_forward->next;
          cur = cur->next;
      }
      auto dummy_head = cur->next;
      cur->next = nullptr;
      k_forward->next = L;
      return dummy_head;
  }
  return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "k"};
  return GenericTestMain(
      args, "list_cyclic_right_shift.cc", "list_cyclic_right_shift.tsv",
      &CyclicallyRightShiftList, DefaultComparator{}, param_names);
}
