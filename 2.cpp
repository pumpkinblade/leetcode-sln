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
  ListNode *reverse(ListNode *l) {
    if (l == nullptr)
      return l;
    ListNode *next = l->next;
    l->next = nullptr;
    while (next) {
      ListNode *tmp = l;
      l = next;
      next = next->next;
      l->next = tmp;
    }
    return l;
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *r1 = l1;
    ListNode *r2 = l2;
    ListNode *l = nullptr;
    int carry = 0;
    while (r1 && r2) {
      int val = r1->val + r2->val + carry;
      carry = val / 10;
      val = val % 10;
      l = new ListNode(val, l);
      r1 = r1->next;
      r2 = r2->next;
    }
    while (r1) {
      int val = r1->val + carry;
      carry = val / 10;
      val = val % 10;
      l = new ListNode(val, l);
      r1 = r1->next;
    }
    while (r2) {
      int val = r2->val + carry;
      carry = val / 10;
      val = val % 10;
      l = new ListNode(val, l);
      r2 = r2->next;
    }
    if (carry) {
      l = new ListNode(carry, l);
    }
    return reverse(l);
  }
};

void printList(ListNode *l) {
  while (l) {
    std::cout << l->val << "->";
    l = l->next;
  }
  std::cout << '\n';
}

int main(void) {
  ListNode *x1 = new ListNode(2);
  ListNode *x2 = new ListNode(4);
  ListNode *x3 = new ListNode(3);
  x1->next = x2;
  x2->next = x3;

  ListNode *y1 = new ListNode(5);
  ListNode *y2 = new ListNode(6);
  ListNode *y3 = new ListNode(4);
  y1->next = y2;
  y2->next = y3;

  ListNode *z = Solution{}.addTwoNumbers(x1, y1);
  printList(z);
  return 0;
}
