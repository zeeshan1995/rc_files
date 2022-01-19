#include "list_node.h"
#include "test_framework/generic_test.h"

bool IsLinkedListAPalindrome(shared_ptr<ListNode<int>> L) {
  // TODO - you fill in here.
  if(!L || !L->next)
      return true;
  auto fast = L->next, slow = L;

  while(fast->next and fast->next->next)
  {
      slow = slow->next;
      fast = fast->next->next;
  }
  auto mid = slow;
  
  if(fast->next)
  {
      slow = slow->next;
      fast = fast->next;
      mid = mid->next;
  }

  auto reverse = slow->next;
  slow = reverse->next;
  while(slow)
  {
      auto tmp = slow->next;
      slow->next = reverse;
      reverse = slow;
      slow = tmp;
  }
  mid->next->next = nullptr;
  mid->next = reverse;
  mid = mid->next;
  while(mid)
  {
      if(L->data != mid->data)
          return false;
      L = L->next;
      mid = mid->next;
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "is_list_palindromic.cc",
                         "is_list_palindromic.tsv", &IsLinkedListAPalindrome,
                         DefaultComparator{}, param_names);
}
