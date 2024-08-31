#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int length(ListNode *head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
  }

  ListNode *impl(std::vector<ListNode *> lists, int l, int r) {
    if (l > r)
      return nullptr;
    if (l == r)
      return lists[l];
    ListNode *l1 = impl(lists, l, (l + r) / 2);
    ListNode *l2 = impl(lists, (l + r) / 2 + 1, r);

    ListNode start(0, nullptr);
    ListNode *curr = &start;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        curr = curr->next = l1;
        l1 = l1->next;
      } else {
        curr = curr->next = l2;
        l2 = l2->next;
      }
    }
    while (l1) {
      curr = curr->next = l1;
      l1 = l1->next;
    }
    while (l2) {
      curr = curr->next = l2;
      l2 = l2->next;
    }

    return start.next;
  }

  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    return impl(lists, 0, lists.size() - 1);
  }
};
