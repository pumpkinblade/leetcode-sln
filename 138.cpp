
// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr)
      return nullptr;

    Node *t = head;
    while (t) {
      Node *n = new Node(t->val);
      n->random = t->random;
      n->next = t->next;
      t->next = n;
      t = n->next;
    }

    t = head;
    while (t) {
      Node *n = t->next;
      if (n->random)
        n->random = n->random->next;
      t = n->next;
    }

    Node *cpy = head->next;
    head->next = cpy->next;
    cpy->next = nullptr;
    Node *r = cpy;
    t = head->next;
    while (t) {
      r = r->next = t->next;
      t = t->next = r->next;
    }
    return cpy;
  }
};
