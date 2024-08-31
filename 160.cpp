struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = length(headA);
    int lenB = length(headB);
    while (lenA < lenB) {
      headB = headB->next;
      lenB--;
    }
    while (lenB < lenA) {
      headA = headA->next;
      lenA--;
    }
    while (headA != headB) {
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }
};
