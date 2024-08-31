#include <functional>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int sumNumbers(TreeNode *root) {
    int res = 0;
    std::function<void(TreeNode *, int)> f = [&](TreeNode *r, int x) {
      if (r == nullptr)
        return;

      x = x * 10 + r->val;
      if (r->left == nullptr && r->right == nullptr)
        res += x;
      else {
        f(r->left, x);
        f(r->right, x);
      }
    };
    f(root, 0);
    return res;
  }
};
