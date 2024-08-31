#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>

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
  std::pair<int, int> impl(TreeNode *root) const {
    if (root == nullptr)
      return {std::numeric_limits<int>::min(), std::numeric_limits<int>::min()};
    auto [xl, yl] = impl(root->left);
    auto [xr, yr] = impl(root->right);

    auto xm = std::max({xl, xr, 0}) + root->val;
    auto ym = std::max({yl, yr, xm});
    if (root->left && root->right) {
      ym = std::max(ym, xl + root->val + xr);
    }

    // std::cout << root->val << " : " << xm << ' ' << ym << '\n';
    return {xm, ym};
  }

  int maxPathSum(TreeNode *root) {
    int res = std::numeric_limits<int>::min();
    auto [x, y] = impl(root);
    return y;
  }
};

int main(void) {
  TreeNode n1(-10);
  TreeNode n2(9);
  TreeNode n3(20);
  TreeNode n4(15);
  TreeNode n5(7);
  n1.left = &n2;
  n1.right = &n3;
  n3.left = &n4;
  n3.right = &n5;
  int res = Solution{}.maxPathSum(&n1);
  std::cout << res << '\n';
  return 0;
}
