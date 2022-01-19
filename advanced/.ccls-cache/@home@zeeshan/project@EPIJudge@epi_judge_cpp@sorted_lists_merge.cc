#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  // TODO - you fill in here.
  auto result = shared_ptr<ListNode<int>>{new ListNode<int>{0}};
  result->next.reset(new ListNode<int>{});

  auto end = result;
  while(L1 and L2)
  {
      if(L1->data <= L2->data)
      {
          end->next->data = L1->data;
          end->next->next.reset(new ListNode<int>{});
          L1 = L1->next;
      }
      else
      {
          end->next->data = L2->data;
          end->next->next.reset(new ListNode<int>{});
          L2 = L2->next;
      }
      end = end->next;
  }
  while(L1)
  {
      end->next->data = L1->data;
      end->next->next.reset(new ListNode<int>{});
      L1 = L1->next;
      end = end->next;
  }
  while(L2)
  {
      end->next->data = L2->data;
      end->next->next.reset(new ListNode<int>{});
      L2 = L2->next;
      end = end->next;
  }
  end->next = nullptr;
  return result->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
