#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>>& L) {
  // TODO - you fill in here.
  if(not L or not L->next)
      return L;
  auto even = L, odd = L->next;
  auto even_head = L, odd_head = odd;
  auto curr = odd;
  int index = 2;
  while(curr->next)
  {
      if(index%2)
      {
          odd->next = curr->next;
          odd = odd->next;
      }
      else
      {
          even->next = curr->next;
          even = even->next;
      }
      curr = curr->next;
      ++index;
  }
  even->next = odd_head;
  odd->next = nullptr;
  return even_head;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "even_odd_list_merge.cc",
                         "even_odd_list_merge.tsv", &EvenOddMerge,
                         DefaultComparator{}, param_names);
}
