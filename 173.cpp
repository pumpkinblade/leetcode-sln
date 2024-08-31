#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    while (root) {
      stk.push(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode *node = stk.top();
    stk.pop();
    TreeNode *right = node->right;
    while (right) {
      stk.push(right);
      right = right->left;
    }
    return node->val;
  }

  bool hasNext() { return !stk.empty(); }

private:
  std::stack<TreeNode *> stk;
};

int main(void) {
  TreeNode n1(7);
  TreeNode n2(3);
  TreeNode n3(15);
  TreeNode n4(9);
  TreeNode n5(20);
  n1.left = &n2;
  n1.right = &n3;
  n3.left = &n4;
  n3.right = &n5;

  BSTIterator it(&n1);
  do {
    std::cout << it.next() << '\n';
  } while (it.hasNext());
}
