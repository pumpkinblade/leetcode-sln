struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return nullptr;

    ListNode *tail = head;
    head = head->next;
    tail->next = nullptr;
    while (head) {
      ListNode *node = head;
      head = head->next;
      node->next = tail;
      tail = node;
    }
    return tail;
  }
};
