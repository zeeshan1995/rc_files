#include <set>
#include <stdexcept>

#include "list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

std::tuple<int, shared_ptr<ListNode<int>>, shared_ptr<ListNode<int>>> length(shared_ptr<ListNode<int>> l)
{
    auto fast = l, slow = l;
    int len = 0;
    while(fast and fast->next)
    {
        slow = slow->next, fast = fast->next->next;
        ++len;
        if(slow == fast)
        {
            std::cout << "cycle detected\n";
            int cycle_len = 0;
            do
            {
                ++cycle_len;
                fast = fast->next;
            }
            while(fast != slow);
            std::cout << "len --> " << cycle_len << " ";

            auto fast_cycle_len = l;
            len = cycle_len;
            while(cycle_len--)
                fast_cycle_len = fast_cycle_len->next;

            std::cout << "fast_satrt-> " << fast_cycle_len->data << " ";
            auto start = l;
            std::cout << "list-satrt-> " << start->data << " ";
            auto prev = fast_cycle_len;
            if(start == fast_cycle_len)
                std::cout << "same ";
            while(start != fast_cycle_len)
            {
                ++len;
                start = start->next;
                prev = fast_cycle_len;
                fast_cycle_len = fast_cycle_len->next;
            }
            std::cout << "start --> " << start->data << " end --> " << prev->data << " len--> " << len << "\n";
            return {len, start, prev};
        }
    }
    std::cout << "No cycle detected ";
    while(slow)
    {
        ++len;
        slow = slow->next;
    }
    //std::cout << "len --> " << len << "\n";
    return {len, nullptr, nullptr};
}

shared_ptr<ListNode<int>> OverlappingLists(shared_ptr<ListNode<int>> l1,
                                           shared_ptr<ListNode<int>> l2) {
  // TODO - you fill in here.
  std::cout << "processing start\n";
  if(not l1)
      std::cout << "l1 null\n";
  if(not l2)
      std::cout << "l2 null\n";
  if(not (l1 and l2))
      return nullptr;
  auto [len1, start1, end1] = length(l1);
  auto [len2, start2, end2] = length(l2);
  if(start1 and start2 and start1==start2)
      return start1;
  //std::cout << start1->data << " " << end1->data << "\n";
  //std::cout << start2->data << " " << end2->data << "\n";
  std::cout << "processing Done\n";
  std::cout << len1 << " " << len2 << "\n";
  auto dif = std::abs(len1 - len2);
  if(len1 > len2)
  {
      while(dif--)
          l1 = l1->next;
  }
  else
  {
      while(dif--)
          l2 = l2->next;
  }
  while(l1 and l2 and l1!=l2)
      l1 = l1->next, l2 = l2->next;
  return l1;
}
void OverlappingListsWrapper(TimedExecutor& executor,
                             shared_ptr<ListNode<int>> l0,
                             shared_ptr<ListNode<int>> l1,
                             shared_ptr<ListNode<int>> common, int cycle0,
                             int cycle1) {
  if (common) {
    if (!l0) {
      l0 = common;
    } else {
      auto it = l0;
      while (it->next) {
        it = it->next;
      }
      it->next = common;
    }

    if (!l1) {
      l1 = common;
    } else {
      auto it = l1;
      while (it->next) {
        it = it->next;
      }
      it->next = common;
    }
  }

  {
      auto x = l0;
      std::cout << "l0 wihout cycle\n";
      while(x)
      {
          std::cout << x->data << " ";
          x = x->next;
      }
      std::cout << "\n-----\n";
  }
  {
      auto x = l1;
      std::cout << "wihout cycle\n";
      while(x)
      {
          std::cout << x->data << " ";
          x = x->next;
      }
      std::cout << "\n-----\n";
  }

  if (cycle0 != -1 && l0) {
      std::cout << "Puting cycle in l0 \n";
    auto last = l0;
    while (last->next) {
      last = last->next;
    }
    auto it = l0;
    while (cycle0-- > 0) {
      if (!it) {
        throw std::runtime_error("Invalid input data");
      }
      it = it->next;
    }
    last->next = it;
    std::cout << "start-> " << it->data << " end -> " << last->data << "\n";
  }

  if (cycle1 != -1 && l1) {
      std::cout << "Puting cycle in l1 \n";
    auto last = l1;
    while (last->next) {
      last = last->next;
    }
    auto it = l1;
    while (cycle1-- > 0) {
      if (!it) {
        throw std::runtime_error("Invalid input data");
      }
      it = it->next;
    }
    last->next = it;
  }

  std::set<shared_ptr<ListNode<int>>> common_nodes;
  auto it = common;
  while (it && common_nodes.count(it) == 0) {
    common_nodes.insert(it);
    it = it->next;
  }

  auto result = executor.Run([&] { return OverlappingLists(l0, l1); });

  if (!((common_nodes.empty() && result == nullptr) ||
        common_nodes.count(result) > 0)) {
    throw TestFailure("Invalid result");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "l0",     "l1",
                                       "common",   "cycle0", "cycle1"};
  return GenericTestMain(args, "do_lists_overlap.cc", "do_lists_overlap.tsv",
                         &OverlappingListsWrapper, DefaultComparator{},
                         param_names);
}
