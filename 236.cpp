#include <utility>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  bool find(TreeNode *root, TreeNode *p) {
    if (root == p)
      return true;
    if (root == nullptr)
      return false;
    if (find(root->left, p))
      return true;
    if (find(root->right, p))
      return true;
    return false;
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // if (root == nullptr || root == p || root == q)
    //   return root;
    // bool pl = find(root->left, p);
    // bool ql = find(root->left, q);
    // if (pl && ql)
    //   return lowestCommonAncestor(root->left, p, q);
    // if (!pl && !ql)
    //   return lowestCommonAncestor(root->right, p, q);
    // return root;

    return impl(root, p, q);
  }

  TreeNode *impl(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == p || root == q || root == nullptr)
      return root;
    TreeNode *la = impl(root->left, p, q);
    TreeNode *ra = impl(root->right, p, q);
    if (la != nullptr && ra != nullptr)
      return root;
    if (la != nullptr)
      return la;
    return ra;
  }
};
