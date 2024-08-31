#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return nullptr;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != slow && fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast != slow)
      return nullptr;
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};

int main(void) {
  ListNode n3(3);
  ListNode n2(2);
  ListNode n0(0);
  ListNode nn4(-4);
  n3.next = &n2;
  n2.next = &n0;
  n0.next = &nn4;
  nn4.next = &n2;
  auto x = Solution{}.detectCycle(&n3);
  if (x)
    std::cout << x->val << '\n';
  else
    std::cout << "null" << '\n';
  return 0;
}
