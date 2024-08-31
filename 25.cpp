#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  std::pair<int, ListNode *> reverseImpl(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr)
      return {0, head};
    // head -> prev -> node
    ListNode *prev = head->next;
    ListNode *node = prev->next;
    int i = 1;
    for (; i < k && node; i++) {
      prev->next = node->next;
      node->next = head->next;
      head->next = node;
      node = prev->next;
    }
    return {i, prev};
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode start(0, head);
    head = &start;
    int i = 0;
    ListNode *prev = head;
    std::tie(i, head) = reverseImpl(head, k);
    while (i == k) {
      prev = head;
      std::tie(i, head) = reverseImpl(head, k);
    }
    reverseImpl(prev, k);
    return start.next;
  }
};

int main(void) {
  ListNode x1(1);
  ListNode x2(2);
  ListNode x3(3);
  ListNode x4(4);
  ListNode x5(5);
  x1.next = &x2;
  x2.next = &x3;
  x3.next = &x4;
  x4.next = &x5;
  ListNode *node = Solution{}.reverseKGroup(&x1, 3);
  while (node) {
    std::cout << node->val << ' ';
    node = node->next;
  }
  std::cout << '\n';
  return 0;
}
