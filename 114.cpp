#include <functional>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void preorder(TreeNode *n) {
  if (n == nullptr)
    return;
  std::cout << n->val << ' ';
  preorder(n->left);
  preorder(n->right);
}

class Solution {
public:
  void impl(TreeNode *root) const {
    if (root == nullptr)
      return;
    impl(root->right);
    if (root->left == nullptr)
      return;
    impl(root->left);
    TreeNode *prev = root;
    TreeNode *curr = root->left;
    while (curr) {
      prev = curr;
      curr = curr->right;
    }
    prev->right = root->right;
    root->right = root->left;
    root->left = nullptr;
  }

  void flatten(TreeNode *root) { impl(root); }
};

int main(void) {
  TreeNode t1(1);
  TreeNode t2(2);
  TreeNode t3(3);
  TreeNode t4(4);
  TreeNode t5(5);
  TreeNode t6(6);
  t1.left = &t2;
  t1.right = &t5;
  t2.left = &t3;
  t2.right = &t4;
  t5.right = &t6;

  Solution{}.flatten(&t1);
  TreeNode *t = &t1;
  while (t) {
    std::cout << t->val << ' ';
    t = t->right;
  }
  std::cout << '\n';
}
