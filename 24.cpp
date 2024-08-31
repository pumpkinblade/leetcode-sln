struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode start(0, head);
    head = &start;
    // swap head->next, head->next->next
    while (head->next && head->next->next) {
      ListNode *next = head->next;
      head->next = next->next;
      next->next = next->next->next;
      head->next->next = next;
      head = next;
    }
    return start.next;
  }
};
