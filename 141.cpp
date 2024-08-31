#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    do {
      fast = fast == nullptr ? nullptr : fast->next;
      fast = fast == nullptr ? nullptr : fast->next;
      slow = slow == nullptr ? nullptr : slow->next;
    } while (fast != slow);
    return fast != nullptr;
  }
};
