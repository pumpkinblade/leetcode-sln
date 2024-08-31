#include <functional>
#include <vector>

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
  TreeNode *sortedArrayToBST(std::vector<int> &nums) {
    std::function<TreeNode *(int, int)> f = [&](int i, int j) {
      if (i > j)
        return (TreeNode *)nullptr;
      if (i == j)
        return new TreeNode(nums[i]);
      TreeNode *n = new TreeNode(nums[(i + j + 1) / 2]);
      n->left = f(i, (i + j + 1) / 2 - 1);
      n->right = f((i + j + 1) / 2 + 1, j);
      return n;
    };
    return f(0, nums.size() - 1);
  }
};
