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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode start(0, head);
    ListNode *l1 = &start, *l2 = head;
    int i = 1;
    while (i < left && l2) {
      l1 = l2;
      l2 = l2->next;
      i++;
    }
    ListNode *r1 = l1, *r2 = l2;
    while (i < right + 1 && r2) {
      r1 = r2;
      r2 = r2->next;
      i++;
    }

    // reverse [l2, r2)
    if (l2 != r2) {
      ListNode *node = l2;
      ListNode *next = l2->next;
      while (next != r2) {
        ListNode *tmp = node;
        node = next;
        next = next->next;
        node->next = tmp;
      }
    }

    l1->next = r1;
    l2->next = r2;

    return start.next;
  }
};

int main(void) {
  ListNode x1(1);
  ListNode x2(2);
  ListNode x3(3);
  ListNode x4(4);
  ListNode x5(5);
  // x1.next = &x2;
  // x2.next = &x3;
  // x3.next = &x4;
  // x4.next = &x5;

  Solution{}.reverseBetween(&x1, 1, 1);

  ListNode *n = &x1;
  while (n) {
    std::cout << n->val << ' ';
    n = n->next;
  }
  std::cout << '\n';
  return 0;
}
