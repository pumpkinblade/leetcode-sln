#include <functional>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() : val(0), neighbors() {}
  Node(int _val) : val(_val), neighbors() {}
  Node(int _val, std::vector<Node *> _neighbors)
      : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
  void copyDFS(Node *u) {
    if (u->neighbors.empty() || u->neighbors.back()->val != u->val) {
      u->neighbors.push_back(new Node(u->val));
      for (int i = 0; i + 1 < u->neighbors.size(); i++) {
        copyDFS(u->neighbors[i]);
      }
    }
  }

  void assignDFS(Node *u) {
    Node *newU = u->neighbors.back();
    if (newU->neighbors.empty()) {
      for (int i = 0; i + 1 < u->neighbors.size(); i++) {
        Node *v = u->neighbors[i];
        newU->neighbors.push_back(v->neighbors.back());
      }
      for (int i = 0; i + 1 < u->neighbors.size(); i++) {
        assignDFS(u->neighbors[i]);
      }
    }
  }

  void clearDFS(Node *u) {
    if (!u->neighbors.empty() && u->neighbors.back()->val == u->val) {
      u->neighbors.pop_back();
      for (int i = 0; i < u->neighbors.size(); i++) {
        clearDFS(u->neighbors[i]);
      }
    }
  }

  Node *cloneGraph(Node *node) {
    if (node == nullptr)
      return nullptr;
    copyDFS(node);
    Node *newNode = node->neighbors.back();
    assignDFS(node);
    clearDFS(node);
    return newNode;
  }
};

int main(void) {
  Node n1(1);
  Node n2(2);
  Node n3(3);
  Node n4(4);
  n1.neighbors.push_back(&n2);
  n1.neighbors.push_back(&n4);
  n2.neighbors.push_back(&n1);
  n2.neighbors.push_back(&n3);
  n3.neighbors.push_back(&n2);
  n3.neighbors.push_back(&n4);
  n4.neighbors.push_back(&n1);
  n4.neighbors.push_back(&n3);
  Solution{}.cloneGraph(&n1);
}
