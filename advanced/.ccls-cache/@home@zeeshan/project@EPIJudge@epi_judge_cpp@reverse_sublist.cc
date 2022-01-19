#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start, int finish) {
  if(start==finish)
      return L;
  auto const s = start;
  auto count = finish - start;
  auto dummy_head = shared_ptr<ListNode<int>>{new ListNode<int>{}};
  dummy_head->next = L;
  while(start > 1)
  {
      dummy_head = dummy_head->next;
      --start;
  }
  auto cur = dummy_head->next;
  auto next = cur->next;
  std::cout << start << std::endl;
  while(cur and next and count)
  {
      auto tmp = next->next;
      next->next = cur;
      cur = next;
      next = tmp;
      --count;
  }
  dummy_head->next->next = next;
  dummy_head->next = cur;
  return s == 1 ? dummy_head->next : L;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
